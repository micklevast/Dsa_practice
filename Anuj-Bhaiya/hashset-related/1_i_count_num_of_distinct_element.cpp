#include<iostream>
using namespace std;
int main()
{
    int temp=0;
    int distinct_ele=0;
    int arr[]={45,12,32,12,12,45,56,32,23,32,89,78,58};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]==arr[j])
            {
                temp++;
                break;
            }
        }
        if(temp==0)
{        distinct_ele++;
        cout<<"distinct element "<<distinct_ele<<" founded"<<"which is:"<<arr[i]<<endl; }


        temp=0;

    }
    cout<<"total number of distinct number in these given array:"<<distinct_ele<<endl;
}