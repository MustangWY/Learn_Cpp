#ifndef STACK_H_
#define STACK_H_

typedef struct custumer
{   
    char fullname[35];
    double payment;
    /* data */
} Item;

class Stack{
    private:
    enum {Max = 10};
    Item items[Max];
    double total;
    int top;
    public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item);
    bool pop(Item &item);
    void showTotal () const;
};


#endif