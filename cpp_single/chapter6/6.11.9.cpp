#include <iostream>
#include<fstream>
const int Size = 20;
using namespace std;
struct Patrons
{   
    char name[30];
    double donation;
    bool isGrand;
};

int main(void){
    int count=0;
    int Grand_count=0;
    char FileName[Size];
    ifstream inFile;
    cout<<"Please enter the name of the file ";
    cin.getline(FileName,Size);
    inFile.open(FileName);
    if (!inFile.is_open())
    {
        cout<<"File not exist"<<endl;
        cout<<"Program terminating. \n";
        exit(EXIT_FAILURE);
    }
    inFile>>count;
    Patrons *pt = new Patrons[count];
    for (int i = 0; i < count; i++)
    {
        inFile.get();//上面cin输入之后输入流中剩下一个回车，需要cin.get()将其读走。
        inFile.getline(pt[i].name,30);
        inFile>>pt[i].donation;
        if (pt[i].donation>10000)
        {
            pt[i].isGrand=1;
            Grand_count++;
        }else pt[i].isGrand=0;
        
    }
    cout<<"Here are the Grand Patrons "<<endl;
   for (int i = 0; i < count; i++)
   {    
        if (Grand_count==0)
        {
            cout<<"NONE";
            break;
        }else if (pt[i].isGrand)
        {   
            cout<<fixed;
            cout.precision(2);
            cout.setf(ios_base::showpoint);
            cout<<pt[i].name<<"\t\t"<<pt[i].donation<<endl;
        }
        
   }
   cout<<"Patrions:"<<"\n";

  for (int i = 0; i < count; i++)
     {    
          if ((count-Grand_count)==0)
          {
              cout<<"NONE";
              break;
          }else if ((!pt[i].isGrand))
          {
              cout<<pt[i].name<<"\t\t"<<pt[i].donation<<endl;
          }
        
     }
    

    return 0;
}
