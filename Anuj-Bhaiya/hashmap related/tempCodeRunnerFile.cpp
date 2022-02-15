#include<iostream>
#include<multimap>
using namespace std;
int main()
{
    int arr[]={1,1,0,1,1,0,0};
    int size=sizeof(arr)/sizeof(arr[0]);

    multimap<int,int> mp;

    //change 0 to -1 and now original question is trasform into find_largest_subarray_of givenSum=0
    for(int i=0;i<size;i++)
    {
        if(arr[i]==0)
        arr[i]=(-1); //replace 0 by -1
    }




    cout<<"length of subarray:"<<len_of_subarr<<endl;

}