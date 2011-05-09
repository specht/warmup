#include <stdio.h>

#define T int


class Node
{
public:
    Node(const T& ak_Value)
        : mk_Value(ak_Value)
    {
    }
    
    virtual ~Node()
    {
    }
    
    Node* next()
    {
        return mk_Next_;
    }
    
    void setNext(Node* n)
    {
        mk_Next_ = n;
    }
    
    const T& value()
    {
        return mk_Value;
    }
    
private:
    T mk_Value;
    Node* mk_Next_;
};


class LinkedList
{
public:
    LinkedList()
        : mk_Root_(0)
    {
    }
    
    virtual ~LinkedList()
    {
    }
    
    void append(const T& ak_Item)
    {
        Node* prev = 0;
        Node* curr = mk_Root_;
        while (curr)
        {
            prev = curr;
            curr = curr->next();
        }
        
        Node* n = new Node(ak_Item);
        if (prev)
            prev->setNext(n);
        else
            mk_Root_ = n;
    }
    
    int length()
    {
        int l = 0;
        for (Node* p = mk_Root_; p; ++l, p = p->next());
        return l;
    }
    
    void print()
    {
        printf("Length: %d\n", this->length());
        for (Node* p = mk_Root_; p; p = p->next())
            printf("%d ", p->value());
        printf("\n");
    }
    
private:
    Node* mk_Root_;
};


int main(int argc, char** argv)
{
    LinkedList l;
    l.append(0);
    l.print();
    l.append(2);
    l.print();
    l.append(5);
    l.print();
    l.append(1);
    l.print();
    return 0;
}
