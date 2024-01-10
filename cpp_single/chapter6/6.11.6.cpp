#include <iostream>
using namespace std;
struct Patrons
{   
    char name[30];
    double donation;
    
};

int main(void){
    int count=0;
    bool is_empty=true;//标志位，用以判定两个列表之中的人是否为空。
    cout<<"Please enter the number of the patrons: ";
    while (!(cin>>count))
    {
        cin.clear();
        while (cin.get()!='\n')
        continue;
        cout<<"Please enter a number."<<endl;
    }
    Patrons *pt = new Patrons[count];
    for (int i = 0; i < count; i++)
    {
        cout<<"Please enter the patron's name: ";
        cin.get();//上面cin输入之后输入流中剩下一个回车，需要cin.get()将其读走。
        cin.getline(pt[i].name,30);
        cout<<"And donations: ";
        while (!(cin>>pt[i].donation))
        {
            cin.clear();
            while (cin.get()!='\n')
            continue;
            cout<<"Please enter a number."<<endl;
            
        }
    }
    cout<<"***Here are the Grand Patrons***"<<endl;
   for (int i = 0; i < count; i++)
   {    
        if (pt[i].donation>10000)
        {   cout<<fixed;
            cout.precision(2);
            cout.setf(ios_base::showpoint);
            cout<<pt[i].name<<"\t\t"<<pt[i].donation<<endl;
            cout<<"NONE";
            is_empty=false;//对所有捐赠人进行扫描，有donation大于10000的人，就将is_empty置为假。
        }
        if (is_empty==true)
        {   
            cout<<"None."<<endl;
            break;
        }
        
   }
   is_empty=true;
    cout<<"***********Patrions:*************"<<"\n";

  for (int i = 0; i < count; i++)
     {    
          if (pt[i].donation<=10000)
          {
              cout<<pt[i].name<<"\t\t"<<pt[i].donation<<endl;
              is_empty=false;
          } 
          if (is_empty==true)
          {
              cout<<"none."<<endl;
              break;
          }
        
     }
    

    return 0;
}
