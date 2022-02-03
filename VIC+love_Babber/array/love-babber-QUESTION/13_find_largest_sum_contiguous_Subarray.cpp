#include<iostream>
using namespace std;
int largest_sum_sub_array(int arr[],int size)
{
    int max_sum=0;
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
        if(sum>max_sum)
        {
            max_sum=sum;
        }
        if(sum<0)
        {
            sum=0;
        }

    }
    return max_sum;
}
int main()
{
    // int arr[]={6,2,3,-5,4,-1,8,7,-9,5,2,4}
    int arr[]={6,2,3,-5,14,1,-1 8};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"The max sum sub-array:"<< largest_sum_sub_array(arr,size);
}
