#ifndef STACK_H_
#define STACK_H_

typedef unsigned long int Item;

class Stack{
    private:
    enum {Max = 10};
    Item items[Max];
    int top;
    public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item);
    bool pop(Item &item);

};


#endif