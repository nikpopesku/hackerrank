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

    Node(Node* p, Node* n, const int k, const int val) : prev(p), next(n), key(k), value(val)
    {
    };

    Node(const int k, const int val) : next(nullptr), prev(nullptr), value(val), key(k)
    {
    };
};

class Cache
{
protected:
    map<int, Node*> mp; //map the key to the node in the linked list
    int cp = 0; //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function
};

class LRUCache : public Cache
{
public:
    explicit LRUCache(int capacity) : cp(capacity)
    {
    }

    void set(const int key, int value) override
    {
        mp[key] = new Node(value);
    }

    int get(const int key) override
    {
        if (mp.find(key) != mp.end())
        {
            return mp[key];
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
