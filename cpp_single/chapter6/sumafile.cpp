/*#include<fstream>
#include<iostream>
#include<cstdlib>
using namespace std;
const int SIZE = 60;
int main(void){
    char filename[SIZE];
    cout<<"Enter name of data file: ";
    cin.getline(filename,SIZE);
    ifstream inFile;
    inFile.open(filename);
    if(!inFile.is_open()){
        cout<<"Could not open the file "<<filename<<endl;
        cout<<"Program terminated."<<endl;
        exit(EXIT_FAILURE);
    }
    cout<<"successfully opened the file!"<<endl;
    double value;
    double sum = 0.0;
    int count = 0;
    inFile>>value;
    while (inFile.good())
    {
        ++count;
        sum+=value;
        inFile>>value;
        cout<<value<<endl;
        
    }
    if (inFile.eof())   
        cout<<"File end reached."<<endl;
    else if (inFile.fail())
        cout<<"Input terminated by data mismatch.\n";
    else 
        cout<<"Terminated by unknown reason.\n";
    if(count==0)
        cout<<"No data processed.\n";
    else{
        cout<<"Items read : "<<count<<endl;
        cout<<"Sum = "<<sum<<endl;
        cout<<"Average = "<<sum/count<<endl;
    }
    inFile.close();
    return 0;
}
*/
// sumafile.cpp -- functions with an array argument
#include <iostream>
#include <fstream>          // file I/O support
#include <cstdlib>          // support for exit()
const int SIZE = 60;
int main()
{
    using namespace std;
    char filename[SIZE];
    ifstream inFile;        // object for handling file input

    cout << "Enter name of data file: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);  // associate inFile with a file
    if (!inFile.is_open())  // failed to open file
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        // cin.get();    // keep window open
        exit(EXIT_FAILURE);
    }
    double value;
    double sum = 0.0;
    int count = 0;          // number of items read

    inFile >> value;
    cout<<value<<endl;        // get first value
    while (inFile.good())   // while input good and not at EOF
    {
        ++count;            // one more item read
        sum += value;       // calculate running total
        inFile >> value;
        cout<<value<<endl; 
        
    }
    if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";
    if (count == 0)
        cout << "No data processed.\n";
    else
    {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }
    inFile.close();         // finished with the file
    // cin.get();
    return 0;
}
