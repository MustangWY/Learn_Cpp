#ifndef STACK_H_
#define STACK_H_

typedef unsigned long int Item;

void visit_Item ( Item & );
class List{
    private:
    enum {Max = 10};
    Item items[Max];
    int top;
    public:
    List();
    bool isempty() const;
    bool isfull() const;
    bool Add(const Item &item);
    void visit(void (*pf)(Item&));

};


#endif