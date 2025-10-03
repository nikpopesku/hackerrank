#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message
{
    string text_;
    int order_;
    int static counter_order_;

public:
    Message() : order_(++counter_order_)
    {
    }

    explicit Message(const string& text) : text_(text), order_(++counter_order_)
    {
    }

    const string& get_text()
    {
        return text_;
    }

    bool operator<(const Message& other) const
    {
        return order_ < other.order_;
    }
};

class MessageFactory
{
public:
    MessageFactory()
    {
    }

    Message create_message(const string& text)
    {
        Message m(text);

        return m;
    }
};

class Recipient
{
public:
    Recipient()
    {
    }

    void receive(const Message& msg)
    {
        messages_.push_back(msg);
    }

    void print_messages()
    {
        fix_order();
        for (auto& msg : messages_)
        {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }

private:
    void fix_order()
    {
        sort(messages_.begin(), messages_.end());
    }

    vector<Message> messages_;
};

class Network
{
public:
    static void send_messages(vector<Message> messages, Recipient& recipient)
    {
        // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());
        for (auto msg : messages)
        {
            recipient.receive(msg);
        }
    }
};

int Message::counter_order_ = 0;

int main()
{
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text))
    {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
