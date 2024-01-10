#include<iostream>
using namespace std;
enum cal {addd=1,subtractt=2,multiplyy=3,dividee=4};
double add(double x, double y);
double calculate(double x, double y,double (*pt)(double x,double y));
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
int main(void){
    double (*pt[4]) (double x, double y) = {add,subtract,divide,multiply};
    cout<<"Please enter two numbers: (q to quit)\n";
    double x,y;
    double result;
    while (cin>>x>>y)
    {  
        cout<<"Please enter the methord of your calculation:\n";
        cout<<"1): add                          2): subtract\n";
        cout<<"3): multiply                     4): divide.\n";
        int i;
        cal me;
        cin>>i;
        me=(cal)i;
        switch (me)
        {
            case addd:result = calculate(x,y,(*pt[0]));
                    cout<<x<<"+"<<y<<"="<<result<<endl;
                    break;
            case subtractt:result = calculate(x,y,(*pt[1]));
                    cout<<x<<"-"<<y<<"="<<result<<endl;  
                    break;
            case multiplyy:result = calculate(x,y,(*pt[3]));
                    cout<<x<<"*"<<y<<"="<<result<<endl;
                    break;
            case dividee:result = calculate(x,y,(*pt[2]));
                    cout<<x<<"/"<<y<<"="<<result<<endl;
                    break;
            default:cout<<"Please enter the correct methord.\n";
            break;
        }
        cout<<"Please enter two numbers: (q to quit)\n";
        /* code */
    }
    cin.get();
    return 0;
}
double add(double x, double y){
    return x+y;
}
double calculate(double x, double y,double (*pt)(double x,double y)){
    return (*pt)(x,y);
}
double subtract(double x, double y){
    return x-y;
}
double divide(double x, double y){
    if (y==0)
    {
        cout<<"y is 0, error.\n";
        return 0;
    }else
    return x/y;
}
double multiply(double x, double y){
    return x*y;
}