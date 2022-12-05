#include <iostream>
using namespace std;
int main(){
    int ip_adress[4];
    cout<<"Enter the IP Address :";
    for(int i = 0;i<4;i++){
        cin>>ip_adress[i];
    }
    cout<<"\nEnter IP Address :"<<ip_adress[0]<<"."<<ip_adress[1]<<"."<<ip_adress[2]<<"."<<ip_adress[3];
    cout<<"\nClass IP Address :";
    if(ip_adress[0]>=0 && ip_adress[0]<=127){
        cout<<"Class A\n";
        cout<<"\nNet ID :"<<ip_adress[0]<<"\nHost ID :"<<ip_adress[1]<<"."<<ip_adress[2]<<"."<<ip_adress[3]<<endl;
    }
    else if(ip_adress[0]>127 && ip_adress[0]<=191){
        cout<<"Class B\n";
        cout<<"\nNet ID :"<<ip_adress[0]<<"."<<ip_adress[1]<<"Host ID :"<<ip_adress[2]<<"."<<ip_adress[3]<<"."<<endl;
    }
    else if(ip_adress[0]>191 && ip_adress[0]<=223){
        cout<<"Class C\n";
        cout<<"\nNet ID :"<<ip_adress[0]<<"."<<ip_adress[1]<<"."<<ip_adress[2]<<"Host ID :"<<ip_adress[3]<<"."<<endl;
    }
    else if(ip_adress[0]>223 && ip_adress[0]<=239){
         cout<<"Class D\n";
        cout<<"\nNet ID :"<<ip_adress[0]<<"."<<ip_adress[1]<<"."<<ip_adress[2]<<"."<<ip_adress[3]<<"."<<endl;
    }
    else if(ip_adress[0]>239 && ip_adress[0]<255){
        cout<<"Class E\n";
    }
    else{
        cout<<"Invalid IP Address...";
    }
    return 0;
}