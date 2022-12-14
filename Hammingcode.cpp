

#include<iostream>								//To import basic input-output functions!
#include<cmath>									//To import power function!
using namespace std;							//Explicitly declaring the namespace that is being used in this program to avoid namespace-clashing and enable hassle-free & clean coding!

int main()										//main() does not receive any arguments from the command line!
{
    cout<<"SENDER SIDE:";
    int m,r;
    do											//Size of the message should not be less than 1!
    {
        cout<<"\nEnter no. of data bits: ";
        cin>>m;
    } while (m<=0);

    int message[m];								//Original Message!
    cout<<"\nEnter the binary message: ";
    for (int i=m-1;i>=0;i--)
        cin>>message[i];

    for (int i=2;i;i++)							//To Calculate no. of redundant bits!
    {
        if ((int)pow(2,i)>=(m+i+1))				//2^r >= m+r+1, pow() returns a double value!
        {
            r=i;
            break;
        }
    }

    int sentData[m+r];
    for (int i=0,x=0,j=0;j<m+r;j++)				//Initialising the data string with the original message at position of the data bits!
    {
        if ((int)pow(2,i)!=j+1)
            sentData[j]=message[x++];
        else
            i++;
    }

    for (int i=0;i<r;i++)						//To calculate the even parity of the parity bits and initialising them into the data string!
    {
        sentData[(int)pow(2,i)-1]=0;
        for (int j=1;j<=m+r;j++)				//Calculating even parity of the ith parity bit!
            if ((j & (int)pow(2,i))==(int)pow(2,i))
                sentData[(int)pow(2,i)-1]=sentData[(int)pow(2,i)-1]^sentData[j-1];
    }

    cout<<"\nMessage Sent by Sender: ";
    for (int i=(m+r-1);i>=0;i--)				//Printing the message sent by sender!
        cout<<sentData[i]<<" ";
    cout<<"\n";

    cout<<"\nRECEIVER SIDE:";
    int recievedData[m+r];
    cout<<"\nEnter Received Message: ";			//Retrieving the received message from user!
    for (int i=m+r-1;i>=0;i--)
        cin>>recievedData[i];

    int c=0;
    for (int i=0;i<r;i++)						//To check For Errors in the received message!
    {
        int p=recievedData[(int)pow(2,i)-1];
        for (int j=1;j<=m+r;j++)
            if (j!=(int)pow(2,i) && (j & (int)pow(2,i))==(int)pow(2,i))
                p=p^recievedData[j-1];

        c+=(int)pow(2,i)*p;
    }

    if (c!=0)									//Printing the corrected received message in case of any error!
    {
        cout<<"\nError in bit "<<c<<"!";
        recievedData[c-1]=!recievedData[c-1];
        cout<<"\nThe Corrected Received Message: ";
        for (int j=m+r-1;j>=0;j--)
            cout<<recievedData[j]<<" ";
        cout<<"\n";
    }
    else										//Printing a desired message in case of no errors in the received message!
        cout<<"\nNo Errors Found in the Received Message!\n";
    return 0;
}