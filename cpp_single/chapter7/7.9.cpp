#include<iostream>
using namespace std;
const int SLEN = 30;
struct student
{   
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
    /* data */
};
int getinfo(student pa[],int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[],int n);
int main(void){
    cout<<"Enter class size: ";
    int class_size;
    cin>>class_size;
    while (cin.get()!='\n')
    {   
        continue;
        /* code */
    }
    student* ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu,class_size);
    for (int i = 0; i < entered; i++)
    {   display1(ptr_stu[i]);
        display2(&ptr_stu[i]);

        /* code */
    }
    display3(ptr_stu,entered);
    delete [] ptr_stu;
    cout<<"Done\n";
    cin.get();
    return 0;
}

int getinfo(student pa[],int n){
    int i;
    student temp;
    cout<<"Enter the name, hobby, and opplevel of the student.Enter blank student name to quit.\n";
   for ( i = 0; i < n; i++)
   {    
        cout<<"Student name: ";
        cin.getline(temp.fullname,SLEN);
        if (temp.fullname[0] == ' ')
        {
            break;
        }
        cout<<"Student hobby: ";
        cin.getline(temp.hobby,SLEN);
        cout<<"Student opplevel: ";
       if (!(cin>>temp.ooplevel))
       {    
            cin.clear();
            while (cin.get()!='\n')
            {   
                continue;
                /* code */
            }
            cout<<"Bad input.\n";
            break;
        /* code */
       }
       cin.get();
       pa[i]=temp;
    /* code */
   }
    return i;
}
void display1(student st){
    cout<<"display1: \n";
    cout<<"student name: "<<st.fullname<<endl;
    cout<<"Student hobby: "<<st.hobby<<endl;
    cout<<"Student ooplevel: "<<st.ooplevel<<endl;
}
void display2(const student *ps){
    //display1(*ps);
    cout<<"display2: \n";
    cout<<"student name: "<<ps->fullname<<endl;
    cout<<"Student hobby: "<<ps->hobby<<endl;
    cout<<"Student ooplevel: "<<ps->ooplevel<<endl;
}

void display3(const student pa[],int n){
    cout<<"display3: \n";
    for (int i = 0; i < n; i++)
    {   
        display1(pa[i]);
        /* code */
    }
    

}