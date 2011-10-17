#ifndef KATCP_MESSAGE_H
#define KATCP_MESSAGE_H

#include <sstream>
#include <string>
#include <vector>

typedef std::string           KatcpArg;
typedef std::vector<KatcpArg> KatcpArgs;

class KatcpType
{
public:
    enum
    {
        REPLY = 33,
        INFORM = 35,
        REQUEST = 63,
    };
};

namespace Katcp
{
    const KatcpArg success = "ok";
    const KatcpArg failure = "fail";
}

class KatcpMessage
{
public:
    KatcpMessage(char type = KatcpType::INFORM, KatcpArg name = "", int id = 0);
    KatcpMessage(const KatcpMessage &msg);
    KatcpMessage &operator=(const KatcpMessage &msg);
    virtual ~KatcpMessage();

    bool reply_ok() const;

    template <typename T>
    void add_arg(T arg);

    KatcpArg serialize() const;
    static KatcpMessage parse(const KatcpArg &raw_msg);

    bool operator==(const KatcpMessage &msg) const;
    bool operator!=(const KatcpMessage &msg) const;
    friend std::ostream& operator<<(std::ostream&, const KatcpMessage&);

    // Accessors
    int       type() const { return m_type; }
    KatcpArg  name() const { return m_name; }
    int       id()   const { return m_id; }
    KatcpArgs args() const { return m_args; }

//protected:
    KatcpArg escape_arg(const KatcpArg &arg) const;
    KatcpArg unescape_arg(const KatcpArg &arg) const;
    KatcpArgs escape_args(const KatcpArgs &args) const;
    KatcpArgs unescape_args(const KatcpArgs &args) const;

private:
    char      m_type;
    KatcpArg  m_name;
    int       m_id;
    KatcpArgs m_args;
};

template <>
inline
void
KatcpMessage::add_arg<KatcpArg>(KatcpArg arg)
{
    m_args.push_back(arg);
}

template <>
inline
void
KatcpMessage::add_arg<const char*>(const char *arg)
{
    m_args.push_back(arg);
}

template <typename T>
inline
void
KatcpMessage::add_arg(T arg)
{
    std::ostringstream parse;
    parse << arg;
    m_args.push_back(parse.str());
}

#endif//KATCP_MESSAGE_H
