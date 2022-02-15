#include<iostream>
using namespace std;
int main()
{
    int arr[]={10,15,-5,15,-10,5};
    int givenSum=5;

    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
    {
        int sum=0;
        for(int j=i;j<size;j++)
        {
            if(arr[j]<=givenSum)
            {
                sum+=arr[j];
            }
            if(sum==givenSum)
            {
                cout<<"Subarray is from "<<i<<" to "<<j<<endl;
                break;
            }
            if(sum>givenSum)
            {
                sum=0;
                break;
            }
        }
    }

}