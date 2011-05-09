#include <stdio.h>
#include <string>
#include <utility>
#include <iostream>

using namespace std;
// HASH_SIZE must be power of two!
const int HASH_SIZE = 1024;


typedef struct ListItem
{
    ListItem()
        : next(0)
    {
    }
    
    ListItem(string _key, string _value)
        : next(0)
        , key(_key)
        , value(_value)
    {
    }
    
    ListItem *next;
    string key;
    string value;
} ListItem;


class LinkedList
{
public:
    LinkedList()
        : root(0)
    {
    }
    
    virtual ~LinkedList()
    {
        ListItem* node = root;
        while (node)
        {
            ListItem* next = node->next;
            delete node;
            node = next;
        }
    }
    
    void prepend(string key, string value)
    {
        ListItem* node = new ListItem(key, value);
        node->next = root;
        root = node;
    }
    
    ListItem* search(string key)
    {
        for (ListItem* node = root; node; node = node->next)
        {
            if (node->key == key)
                return node;
        }
        return 0;
    }
    
private:
    ListItem* root;
};


class Hash
{
public:
    Hash();
    virtual ~Hash();
    
    void add(string key, string value);
    string lookup(string key);
    
private:
    unsigned int calcHash(string key);
    LinkedList* slots[HASH_SIZE];
};


Hash::Hash()
{
    for (int i = 0; i < HASH_SIZE; ++i)
        slots[i] = new LinkedList();
}


Hash::~Hash()
{
    for (int i = 0; i < HASH_SIZE; ++i)
        delete slots[i];
}


void Hash::add(string key, string value)
{
    unsigned int hash = calcHash(key);
    printf("adding '%s', hash is %d.\n", key.c_str(), hash);
    slots[hash]->prepend(key, value);
}


string Hash::lookup(string key)
{
    unsigned int hash = calcHash(key);
    ListItem* item = slots[hash]->search(key);
    if (item)
        return item->value;
    else
        throw 1;
}


unsigned int Hash::calcHash(string key)
{
    unsigned int hash = 1337;
    for (int i = 0; i < key.length(); ++i)
    {
        hash *= (((int)key[i]) % 17) + 2;
        hash += (((int)key[i]) % 199);
    }
    return hash & (HASH_SIZE - 1);
}


int main(int argc, char** argv)
{
    Hash h;
    h.add("chunky", "1");
    h.add("bacon", "2");
    printf("chunky: %s\n", h.lookup("chunky").c_str());
    printf("bacon: %s\n", h.lookup("bacon").c_str());
    cout << "Yay!" << endl;
}
