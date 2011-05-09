#include <stdio.h>

class Node
{
public:
    Node(int _data)
        : data(_data)
    {
        next[0] = 0;
        next[1] = 0;
    }
    
    virtual ~Node()
    {
        for (int i = 0; i < 2; ++i)
            if (next[i])
                delete next[i];
    }
    
    // right now this is awful, but it works 
    // could be sped up by keeping track of node heights
    int height() const
    {
        int height[2] = {0, 0};
        for (int i = 0; i < 2; ++i)
            if (next[i])
                height[i] = next[i]->height() + 1;
            else
                height[i] = 1;
            
        return (height[0] > height[1]) ? height[0] : height[1];
    }
    
    int balance() const
    {
        int height[2] = {0, 0};
        for (int i = 0; i < 2; ++i)
        {
            if (next[i])
                height[i] = next[i]->height();
            else
                height[i] = 0;
        }
        return height[1] - height[0];
    }
    
    void print(int level = 0)
    {
        if (next[1])
            next[1]->print(level + 1);
        for (int i = 0; i < level; ++i)
            printf(" ");
        printf("%d (%d)\n", data, this->balance());
        if (next[0])
            next[0]->print(level + 1);
    }
    
    inline int goesToIndex(int item, int reference) const
    {
        return (item < reference) ? 0 : 1;
    }
    
    // inserts a node
    void insert(Node* other)
    {
        int index = goesToIndex(other->data, this->data);
        if (next[index])
            next[index]->insert(other);
        else
            next[index] = other;
    }
    
    Node* next[2];
    int data;
};


class AVLTree
{
public:
    AVLTree()
        : root(0)
    {
    }
    
    virtual ~AVLTree()
    {
        if (root)
            delete root;
    }
    
    void insert(int i)
    {
        Node* node = new Node(i);
        if (root == 0)
            root = node; 
        else
            root->insert(node);
    }
    
    void print()
    {
        printf("-------------\n");
        if (root)
            root->print();
        printf("-------------\n");
    }
    
private:
    Node* root;
};


int main(int argc, char** argv)
{
    AVLTree tree;
    tree.insert(3);
    tree.print();
    tree.insert(8);
    tree.print();
    tree.insert(9);
    tree.print();
    tree.insert(7);
    tree.print();
    tree.insert(1);
    tree.print();
    tree.insert(4);
    tree.print();
    tree.insert(6);
    tree.print();
}
