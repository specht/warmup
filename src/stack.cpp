#include <stdio.h>

typedef struct r_Node
{
    r_Node* mr_Next_;
    void* mv_Data_;
} r_Node;


class k_Stack
{
public:
    k_Stack()
        : mr_Tos_(0)
    {
    }
    
    virtual ~k_Stack()
    {
    }
    
    void push(void* av_Data_)
    {
        r_Node* lr_Node_ = new r_Node;
        if (!lr_Node_)
            throw 1;
        lr_Node_->mv_Data_ = av_Data_;
        lr_Node_->mr_Next_ = mr_Tos_;
        mr_Tos_ = lr_Node_;
    }
    
    void* pop()
    {
        if (!mr_Tos_)
            return 0;
        
        void* lv_Datum_ = mr_Tos_->mv_Data_;
        r_Node* lr_Temp_ = mr_Tos_->mr_Next_;
        delete mr_Tos_;
        mr_Tos_ = lr_Temp_;
        return lv_Datum_;
    }
    
private:
    r_Node* mr_Tos_;
};


int main(int argc, char** argv)
{
    k_Stack lk_Stack;
    lk_Stack.push((void*)0x11111111);
    lk_Stack.push((void*)0x22222222);
    lk_Stack.push((void*)0x33333333);
    lk_Stack.push((void*)0x44444444);
    for (int i = 0; i < 4; ++i)
        printf("%p\n", lk_Stack.pop());
}
