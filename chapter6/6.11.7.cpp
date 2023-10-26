#include<iostream>
#include<cctype>
using namespace std;
int main(void){
    cout<<"Enter words (q to quit)"<<endl;
    char words[20];
    int v_count,others=0;
    int c_count=0;
    char ch;
    char ch1;
    //cin.get(ch);
    /*while(ch!='q'||ch1!='\n')
    {
        for (int i = 0; i < 20; i++)
        {
            if (ch==' '||ch=='\n')
            {   
                
                if (isalpha(words[0]))
                {
                    switch (words[0])
                    {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    case 'A':
                    case 'E':
                    case 'I':
                    case 'O':
                    case 'U': v_count++;
                        break;
                    default:
                        c_count++;
                        break;
                    }
                }else others++;
                cin.get(ch);
                cin.get(ch1);//向后读一位，判断是否为单独输入q，即q+回车
                break;
            }else{
                words[i]=ch;
                cin.get(ch);
                
            }
            
        }
        
        
    }
    */
   while ((cin>>words)&&(words[0]!='q'))
   {
        if (isalpha(words[0]))
        {
             switch (words[0])
                    {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    case 'A':
                    case 'E':
                    case 'I':
                    case 'O':
                    case 'U': v_count++;
                        break;
                    default:
                        c_count++;
                        break;
                    }
            /* code */
        }else others++;
        
   }
   
    cout<<v_count<<" Words begining with vowels"<<endl;
    cout<<c_count<<" words begining with consonants"<<endl;
    cout<<others<<" others "<<endl;
    return 0;
}


