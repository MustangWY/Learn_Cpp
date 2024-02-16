#include<iostream>
#include"Move.h"

Move::Move(double a, double b){
    x = a;
    y = b;
}

void Move::showMove() const {
    std::cout<<"Current position is ("<<x<<" , "<<y<<")"<<std::endl;
}
Move Move::add(const Move &m) const {
    Move anew;
    anew.x = this->x + m.x;
    anew.y = this->y + m.y;
    return anew;
}

void Move::reset(double a , double b ){
    x = a;
    y = b;
}