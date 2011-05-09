/*
 descend left
 print node
 descend right
 
 when we return:
   from a left node: print node & descend right
   from a right node: done
 */

#include <stdio.h>

class Node;

typedef struct StackItem
{
    StackItem(Node* n, int s)
        : node(n)
        , step(s)
        , next(0)
    {
    }
    
    Node* node;
    int step;
    StackItem* next;
} StackItem;

class Stack
{
public:
    Stack()
        : head(0)
    {
    }
    
    virtual ~Stack()
    {
    }
    
    void push(Node* n, int s)
    {
        StackItem* si = new StackItem(n, s);
        si->next = head;
        head = si;
    }
    
    Node* pop(int* step_ = 0)
    {
        if (!head)
            throw 100;
        StackItem* newHead = head->next;
        Node* result = head->node;
        if (step_)
            *step_ = head->step;
        delete head;
        head = newHead;
        return result;
    }
    
    StackItem* head;
};

class Node
{
public:
    Node(int _data) 
        : data(_data)
        , left(0)
        , right(0)
    {
    }
    
    virtual ~Node()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
    
    void printPreorder()
    {
        printf("%d  ", data);
        if (left)
            left->printPreorder();
        // return point 1
        if (right)
            right->printPreorder();
        // return point 2
    }
    void print()
    {
        if (left)
            left->print();
        // return point 1
        printf("%d  ", data);
        if (right)
            right->print();
        // return point 2
    }
    
    void printNoRecursionPreorder()
    {
        Stack s;
        s.push(this, 0);
        while (true)
        {
            Node* n = 0;
            try
            {
                n = s.pop();
            }
            catch (int e)
            {
                break;
            }
            if (n)
            {
                printf("%d  ", n->data);
                s.push(n->right, 0);
                s.push(n->left, 0);
            }
        }
    }
    
    int data;
    Node* left;
    Node* right;
};


int main(int argc, char** argv)
{
    Node* root = 0;
    Node* n20 = new Node(20);
    Node* n8 = new Node(8);
    Node* n22 = new Node(22);
    Node* n4 = new Node(4);
    Node* n12 = new Node(12);
    Node* n10 = new Node(10);
    Node* n14 = new Node(14);
    root = n20;
    n20->left = n8;
    n20->right = n22;
    n8->left = n4;
    n8->right = n12;
    n12->left = n10;
    n12->right = n14;
    
    root->printPreorder();
    printf("\n");
    root->printNoRecursionPreorder();
    printf("\n");
    
    delete root;
}
