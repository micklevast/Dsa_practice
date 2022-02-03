#include<iostream>
using namespace std;
int brute_forces_method(int *arr,int n);
int maxSum_subarray(int *arr,int n) // kadaen's algorithm
{
   int sum=0;int  max_sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];

        if(max_sum<sum)
        max_sum=sum;

        if(sum<0)
        sum=0;
    }
    return max_sum;
}
int main()
{
    int arr[]={-5,4,6,-3,4,-1}; 
    int size=sizeof(arr)/sizeof(arr[0]);
    // cout<<"max_sum:"<< maxSum_subarray(arr,size)<<endl; // kadaen's algorithm
    cout<<"max_sum:"<< brute_forces_method(arr,size)<<endl; //brute_force-method
}

int brute_forces_method(int *arr,int n)
{
    int currSum=0;int maxSum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            currSum+=arr[j];
            if(maxSum<currSum)
            maxSum=currSum;
        }
        currSum=0;
    }
    return maxSum;
}