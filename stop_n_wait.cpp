#include <iostream>
using namespace std;
int main(){
    int nf ,n;
    int tr = 0;

    cout<<"Enter the number of frames :";
    cin>>nf;

    cout<<"Enter the window size :";
    cin>>n;

    int i = 1;
    while(i<=nf){
        int x=0;
        for(int j = i;j<n+i&&j<=nf;j++){
            cout<<"sent frame"<<j<<endl;
            tr++;
        }
        cout<<"frame not received "<<endl;
    }
    i+=x;
    cout<<"number of transmission"<<tr<<endl;
    return 0;
}