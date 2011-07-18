#ifndef KATCP_MESSAGE_H
#define KATCP_MESSAGE_H

#include <sstream>
#include <string>
#include <vector>

typedef std::string      Arg;
typedef std::vector<Arg> Args;

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
    Message(char type, Arg name, int id = 0);
    Message(const Message &msg);
    virtual ~Message();

    bool reply_ok() const;

    template <typename T>
    void add_arg(T arg);

    Arg serialize() const;
    static Message parse(const Arg &raw_msg);

    bool operator==(const Message &msg) const;
    bool operator!=(const Message &msg) const;
    friend std::ostream& operator<<(std::ostream&, const Message&);

//protected:
    Arg escape_arg(const Arg &arg) const;
    Arg unescape_arg(const Arg &arg) const;
    Args escape_args(const Args &args) const;
    Args unescape_args(const Args &args) const;

private:
    char m_type;
    Arg  m_name;
    int  m_id;
    Args m_args;
};

template <>
void
Message::add_arg<Arg>(Arg arg)
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

#endif//KATCP_MESSAGE_H
