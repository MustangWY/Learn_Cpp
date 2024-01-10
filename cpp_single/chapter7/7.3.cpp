#include<iostream>
using namespace std;
struct box
{   
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
    /* data */
};
box fill_box(box b);
void show_box(box b);
void cal_volume (box*);

int main(void){
    box b = fill_box(b);
    show_box(b);
    cal_volume(&b);
    return 0;
}
box fill_box(box b){
    cout<<"Please enter the maker: \n";
    cin.getline(b.maker,40);
    cout<<"Please enter the height: \n";
    cin>>b.height;
    cout<<"width: \n";
    cin>>b.width;
    cout<<"length: \n";
    cin>>b.length;
    cout<<"volume: \n";
    cin>>b.volume;
    return b;

}
void show_box(box b){
    cout<<"maker: "<<b.maker<<endl;
    cout<<"height: "<<b.height<<endl;
    cout<<"width: "<<b.width<<endl;
    cout<<"length: "<<b.length<<endl;
    cout<<"volume: "<<b.volume<<endl;
}

void cal_volume (box* b){
    b->volume=b->height*b->length*b->width;
    cout<<"volume: "<<b->volume;
}