#include <iostream>
#include <map>
#include <string>
using namespace std;

struct Node
{
    Node* next;
    Node* prev;
    int value;
    int key;

    Node(Node* p, Node* n, const int k, const int val) : next(n), prev(p), value(val), key(k)
    {
    };

    Node(const int k, const int val) : next(nullptr), prev(nullptr), value(val), key(k)
    {
    };
};

class Cache
{
public:
    virtual ~Cache() = default;

protected:
    map<int, Node*> mp; //map the key to the node in the linked list
    int cp; //capacity
    Node* tail = nullptr; // double linked list tail pointer
    Node* head = nullptr; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

    explicit Cache(const int cp) : cp(cp)
    {
    };
};

class LRUCache final : public Cache
{
public:
    explicit LRUCache(const int capacity) : Cache(capacity)
    {
    }

    void set(const int key, const int value) override
    {
        mp[key] = new Node(nullptr, head, key, value);
        head = mp[key];


        if (tail == nullptr)
        {
            tail = head;
        }


        int counter = 2;
        Node* node = head->next;
        Node* previous = head;

        while (node)
        {
            if (counter >= cp)
            {
                auto tmp = node->next;
                node->next = nullptr;
                tail = node;

                while (tmp)
                {
                    mp.erase(tmp->key);
                    tmp = tmp->next;
                }

                break;
            }

            if (node->key == key)
            {
                if (previous != nullptr)
                {
                    previous->next = node->next;
                }

                if (node->next)
                {
                    node->next->prev = previous;
                }
                else
                {
                    tail = node;
                }

                break;
            }

            previous = node;
            node = node->next;
            ++counter;
        }
    }

    int get(const int key) override
    {
        if (mp.find(key) != mp.end())
        {
            return mp[key]->value;
        }

        return -1;
    }
};

int main()
{
    int n, capacity;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "get")
        {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set")
        {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
