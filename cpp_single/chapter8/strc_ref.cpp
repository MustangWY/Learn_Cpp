#include<iostream>
#include<string>
using namespace std;
struct free_throws
{
    string name;
    int made;
    int attempt;
    float percent;
};

void set_pc(free_throws &ft);
void display(const free_throws &ft);
free_throws & accumulate1(free_throws &target, const free_throws &source);

int main(void){

    free_throws one = {"Rick", 13 , 14};
    free_throws two = {"Jack", 10 , 16};
    free_throws three = {"Jerry", 7 , 9};
    free_throws four = {"Jeson", 5 , 9};
    free_throws five = {"Micheal", 6 , 14};
    free_throws team = {"Class 1", 0 , 0};
    set_pc(one);
    display(one);
    display(accumulate1(team,one));
    display(accumulate1(accumulate1(team,two),three));
    display(accumulate1(team,four));

    free_throws dup;
    dup = accumulate1(team,five);
    display(team);
    display(dup);
    return 0;
}
void set_pc(free_throws &ft){
    if (ft.attempt!=0)
    {
        ft.percent = 100.0*float(ft.made)/float(ft.attempt);
    }else ft.percent = 0.0;
    

}
void display(const free_throws &ft){
    cout<<"Name: "<<ft.name<<endl;
    cout<<"Made: "<<ft.made<<'\t';
    cout<<"Attempts: "<<ft.attempt<<'\t';
    cout<<"Percent: "<<ft.percent<<endl;
}
free_throws & accumulate1(free_throws &target, const free_throws &source){
    target.attempt+=source.attempt;
    target.made+=source.made;
    set_pc(target);

    return target;
}