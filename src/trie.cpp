#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <list>
#include <iostream>

using namespace std;

#define INVALID 26

class TrieNode
{
public:
    TrieNode()
        : isWord(false)
    {
        // clear children
        for (int i = 0; i < 26; ++i)
            next[i] = 0;
    }
    
    virtual ~TrieNode()
    {
    }
    
// private:
    bool isWord;
    TrieNode* next[INVALID + 1];
};

class Trie
{
public:
    Trie()
        : root(new TrieNode())
    {
    }
    
    virtual ~Trie()
    {
    }
    
    void insert(const char *s)
    {
        TrieNode* p = root;
        for (int i = 0; i < strlen(s); ++i)
        {
            char c = tolower(s[i]);
            int slot = c - 'a';
            if (!((c >= 'a') && (c <= 'z')))
                slot = INVALID;
            // check whether we already have a child at this slot
            // if not, create one
            if (!p->next[slot])
                p->next[slot] = new TrieNode();
            p = p->next[slot];
        }
        p->isWord = true;
    }
    
    bool isWord(string s)
    {
        TrieNode* p = root;
        for (int i = 0; i < s.length(); ++i)
        {
            char c = tolower(s.at(i));
            int slot = c - 'a';
            if (!((c >= 'a') && (c <= 'z')))
                slot = INVALID;
            p = p->next[slot];
            if (!p)
                return false;
        }
        return p->isWord;
    }
    
private:
    TrieNode* root;
};


int main(int argc, char** argv)
{
    Trie t;
    t.insert("chunky");
    t.insert("bacon");
    t.insert("bachelor");
    t.insert("chuck");
    list<string> words;
    words.push_back("Chunk");
    words.push_back("Chunky");
    words.push_back("ChuNKyS");
    words.push_back("chucky");
    words.push_back("chuCK");
    for (list<string>::const_iterator i = words.begin(); i != words.end(); ++i)
    {
        cout << *i << " is" << (t.isWord(*i) ? " " : " NOT ") << "a valid word." << endl;
    }
}
