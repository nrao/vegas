// Parent
#include "Message.h"
// Local
// YGOR
// STL
#include <sstream>

Message::Message(char type, Arg name, int id)
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

//------//
// join //
//------//
Arg join(const Arg &separator,
         const Args &args)
{
    Arg base;
    Args::const_iterator iter = args.begin();
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

Arg
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
Message::parse(const Arg &raw_msg)
{
    size_t tb = raw_msg.find_first_not_of(" \t");
    char type = raw_msg[tb];

    size_t nb = raw_msg.find_first_not_of(" \t", tb+1);
    size_t ne = raw_msg.find_first_of("[ \t", nb+1);
    Arg name(raw_msg, nb, ne-nb);

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
    } while(ae != Arg::npos);
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

Arg
Message::escape_arg(const Arg &raw_arg) const
{
    if(raw_arg.size() == 0)
    {
        return "\\@";
    }
    Arg arg = raw_arg;
    size_t pos = arg.find_first_of(std::string(" \n\r\t\x1b\0"));
    while(pos != Arg::npos)
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

Arg
Message::unescape_arg(const Arg &esc_arg) const
{
    Arg arg = esc_arg;
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
    } while(pos != Arg::npos);
    return arg;
}

Args
Message::escape_args(const Args &raw_args) const
{
    Args args;
    for(size_t i = 0; i < raw_args.size(); ++i)
    {
        args.push_back(escape_arg(raw_args[i]));
    }
    return args;
}

Args
Message::unescape_args(const Args &esc_args) const
{
    Args args;
    for(size_t i = 0; i < esc_args.size(); ++i)
    {
        args.push_back(unescape_arg(esc_args[i]));
    }
    return args;
}

std::ostream&
operator<<(std::ostream &os, const Message &m)
{
    Arg args = "(" + join(" ", m.escape_args(m.m_args)) + ")";
    os << "<Message "
       << m.m_type << " "
       << m.m_name << " " 
       << args << ">";
    return os;
}
