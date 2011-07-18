//#include "katcp.h"
//#include "katcl.h"

#include <sstream>
#include <string>
#include <vector>

typedef std::string       Name;
typedef std::vector<Name> Arguments;

class MessageType
{
public:
    enum
    {
        REPLY = 33,
        INFORM = 35,
        REQUEST = 63,
    };
};

class Message
{
public:
    Message(char type, Name name, int id = 0);
    Message(const Message &msg);
    virtual ~Message();

    bool reply_ok() const;

    template <typename T>
    void add_arg(T arg);

    Name serialize() const;
    static Message parse(const Name &raw_msg);

    bool operator==(const Message &msg) const;
    bool operator!=(const Message &msg) const;
    friend std::ostream& operator<<(std::ostream&, const Message&);

//protected:
    Name      escape_arg(const Name &arg) const;
    Name      unescape_arg(const Name &arg) const;
    Arguments escape_args(const Arguments &args) const;
    Arguments unescape_args(const Arguments &args) const;

private:
    char      m_type;
    Name      m_name;
    int       m_id;
    Arguments m_args;
};

//---

Message::Message(char type, Name name, int id)
    :
    m_type(type),
    m_name(name),
    m_id(id)
    
{
    m_args.clear();
}

Message::Message(const Message &msg)
    :
    m_type(msg.m_type),
    m_name(msg.m_name),
    m_id(msg.m_id),
    m_args(msg.m_args)
{
}

Message::~Message()
{
    m_args.clear();
}

bool
Message::reply_ok() const
{
    return ((m_type == MessageType::REPLY) &&
            (m_args.size() > 0) &&
            (m_args[0].compare("ok") == 0));
}

#include <iostream>

template <>
void
Message::add_arg<Name>(Name arg)
{
    m_args.push_back(arg);
}

template <>
void
Message::add_arg<const char*>(const char *arg)
{
    m_args.push_back(arg);
}

template <typename T>
void
Message::add_arg(T arg)
{
    std::ostringstream parse;
    parse << arg;
    m_args.push_back(parse.str());
}

//------//
// join //
//------//
Name join(const Name &separator,
          const Arguments &args)
{
    Name base;
    Arguments::const_iterator iter = args.begin();
    if(base.empty() && (iter != args.end()))
    {
        base = *iter;
        ++iter;
    }
    while(iter != args.end())
    {
        base += separator;
        base += *iter;
        ++iter;
    }
    return base;
}

Name
Message::serialize() const
{
    std::ostringstream msg;
    msg << m_type
        << m_name;
    if(m_id != 0)
    {
        msg << "[" << m_id << "]";
    }
    if(m_args.size() > 0)
    {
        msg << " " << join(" ", escape_args(m_args));
    }
    return msg.str();
}

Message
Message::parse(const Name &raw_msg)
{
    size_t tb = raw_msg.find_first_not_of(" \t");
    char type = raw_msg[tb];

    size_t nb = raw_msg.find_first_not_of(" \t", tb+1);
    size_t ne = raw_msg.find_first_of("[ \t", nb+1);
    Name name(raw_msg, nb, ne-nb);

    int ib = ne;
    int ie = ib;
    int id = 0;
    if(raw_msg[ib] == '[')
    {
        ++ib;
        ie = raw_msg.find_first_of("]", ib);
        std::istringstream idss(std::string(raw_msg, ib, ie-ib));
        idss >> id;
    }

    Message msg(type, name, id);

    size_t ab, ae = ie;
    do
    {
        ab = raw_msg.find_first_not_of(" \t", ae+1);
        ae = raw_msg.find_first_of(" \t", ab+1);
        msg.add_arg(raw_msg.substr(ab, ae-ab));
    } while(ae != Name::npos);
    return msg;
}

bool
Message::operator==(const Message &msg) const
{
    return ((m_type == msg.m_type) &&
            (m_name == msg.m_name) &&
            (m_id == msg.m_id) &&
            (m_args == msg.m_args));
}

bool
Message::operator!=(const Message &msg) const
{
    return !(*this == msg);
}

Name
Message::escape_arg(const Name &raw_arg) const
{
    if(raw_arg.size() == 0)
    {
        return "\\@";
    }
    Name arg = raw_arg;
    size_t pos = arg.find_first_of(std::string(" \n\r\t\x1b\0"));
    while(pos != Name::npos)
    {
        switch(arg[pos])
        {
        case ' ':
            arg.replace(pos, 1, "_"); break;
        case '\n':
            arg.replace(pos, 1, "n"); break;
        case '\r':
            arg.replace(pos, 1, "r"); break;
        case '\0':
            arg.replace(pos, 1, "0"); break;
        case '\t':
            arg.replace(pos, 1, "t"); break;
        case '\x1b':
            arg.replace(pos, 1, "e"); break;
        }
        arg.insert(pos, "\\");
        pos = arg.find_first_of(std::string(" \n\r\t\x1b\0"), pos+2);
    }
    return arg;
}

Name
Message::unescape_arg(const Name &esc_arg) const
{
    Name arg = esc_arg;
    if(arg.compare("\\@") == 0)
    {
        return "";
    }
    size_t pos = -1;
    do
    {
        pos = arg.find_first_of("\\", pos+1);
        if(arg[pos] == '\\')
        {
            arg.erase(pos, 1);
            switch(arg[pos])
            {
            case '_':
                arg.replace(pos, 1, " "); break;
            case 'n':
                arg.replace(pos, 1, "\n"); break;
            case 'r':
                arg.replace(pos, 1, "\r"); break;
            case '0':
                arg.replace(pos, 1, "\0"); break;
            case 't':
                arg.replace(pos, 1, "\t"); break;
            case 'e':
                arg.replace(pos, 1, "\x1b"); break;
            }
        }
    } while(pos != Name::npos);
    return arg;
}

Arguments
Message::escape_args(const Arguments &raw_args) const
{
    Arguments args;
    for(size_t i = 0; i < raw_args.size(); ++i)
    {
        args.push_back(escape_arg(raw_args[i]));
    }
    return args;
}

Arguments
Message::unescape_args(const Arguments &esc_args) const
{
    Arguments args;
    for(size_t i = 0; i < esc_args.size(); ++i)
    {
        args.push_back(unescape_arg(esc_args[i]));
    }
    return args;
}

std::ostream&
operator<<(std::ostream &os, const Message &m)
{
    Name args = "(" + join(" ", m.escape_args(m.m_args)) + ")";
    os << "<Message "
       << m.m_type << " "
       << m.m_name << " " 
       << args << ">";
    return os;
}

//#include <algorithm>
#include <cassert>
#include <iostream>

#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

Arguments
split(const Name &s, char delim)
{
    Arguments tokens;
    std::stringstream ss(s);
    Name item;
    while(std::getline(ss, item, delim))
    {
        tokens.push_back(item);
    }
    return tokens;
}

bool
send_message(const Message &request, Message &reply)
{
    static Name waiting_chunk;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    //!!! Make address dynamic
    struct hostent *server = gethostbyname("roach3");

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    memcpy(server->h_addr,
            &serv_addr.sin_addr.s_addr,
            server->h_length);
    //!!! Make port dynamic
    serv_addr.sin_port = htons(7147);

    //!!! Add failure message?
    if(connect(sock, (sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        return false;
    }

    Name raw_msg = request.serialize() + "\n";
    char buffer[100];
    // Clear out connection info
    //!!! Have persistent connection?
    int n = read(sock, buffer, 100);
    memset(buffer, 0, 100);
    n = write(sock, raw_msg.c_str(), raw_msg.size());
    close(sock);

    n = read(sock, buffer, 100);
    Arguments lines = split(buffer, '\n');
    for(int i = 0; i < lines.size()-1; ++i)
    {
        Message m = Message::parse(lines[i]);
        // Do something with message
        //if(m.reply_ok() && (m.m_id() == msg.id()))
        //{
        //    reply = m;
        //}
    }
    waiting_chunk = lines[lines.size()-1];
    return reply.reply_ok();
}

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct hostent *server = gethostbyname("roach3");
    struct sockaddr_in serv_addr;

    serv_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr,
          (char*)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(7147);

    if(!connect(sock, (sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        std::cout << "Failed to connect" << std::endl;
        return 1;
    }

    Message m(MessageType::REQUEST, "help");
    m.add_arg("help");

    Name raw_msg = m.serialize() + "\n";
    char buffer[100];
    int n = read(sock, buffer, 100);
    memset(buffer, 0, 100);
    n = write(sock, raw_msg.c_str(), raw_msg.size());
    n = read(sock, buffer, 100);
    //std::cout << buffer << std::endl;
    Arguments lines = split(buffer, '\n');
    for(int i = 0; i < lines.size(); ++i)
    {
        //std::cout << "'" << lines[i] << "'" << std::endl;
        Message m = Message::parse(lines[i]);
        std::cout << "'" << m.serialize() << "'" << std::endl;
    }

    // Message m(MessageType::REQUEST, "testing", 5);
    // Message m2 = Message::parse("? testing[333] 5 5.123 stuff");
    // m.add_arg(5);
    // m.add_arg(5.123456);
    // m.add_arg("More than one word. Oh, my goodness");
    // m.add_arg("\x1b");
    // Message m3(m);

    // std::cout << m << std::endl;
    // std::cout << m.serialize() << std::endl;
    // std::cout << m2 << std::endl;
    // std::cout << m2.serialize() << std::endl;
    // std::cout << m3.serialize() << std::endl;

    // assert(m == m3);
    // assert(m != m2);

    return 0;
}
