#include <iostream>
#include <string>
int main(void){
    int a = 0;
    int b = 0;
    std::cout<<"123:";
    std::cin >> a;
    std::cout << "456:";
    std::cin >>b;
    char abc[10];
    char bcd[10];
    std::cout<<"abc:";                  
    /*是否需要使用cin.get()吃掉输入流中的回车要依据下一次读取的方式而定。
    如使用cin.getline()或类C输入scanf()或put()等的时候，
    就需要用cin.get()在下一次读取前清空残余缓存；若使用cin>>则不需要，
    因为cin是智能指针，它将跳过缓冲区的无效字符（如这里的回车），
    直到找到非空白字符为止，然后它将读取字符，直到再次遇到空白为止。
    */
    std::cin.get();
    std::cin.getline(abc,10);
    std::cout<<"bcd:";
    std::cin>>bcd;
    


}