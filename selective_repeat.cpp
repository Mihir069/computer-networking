#include <iostream>
using namespace std;
int main(){
    int w,i,f,frame[50];
    cout<<"Enter window size :";
    cin>>w;
    cout<<"Enter the number of frame to transmit :";
    cin>>f;
    cout<<"Enter frames :"<<f<<endl;
    for(i;i<=f;i++){
        cin>>frame[i];
    }
    for(i=1;i<=f;i++){
        if(i%w==0){
            cout<<frame[i]<<endl;
            cout<<"frames sent is received by sender"<<endl;
        }
        else{
            cout<<frame[i];
        }
    }
    if(f%w!=0){
        cout<<"frames sent is received by sender"<<endl;
    }
    return 0;
}