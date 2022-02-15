#include<iostream>
#include<map>
using namespace std;

void printMap(map<int,int>m)
{
    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" -> "<<it->second<<endl;
    }
    cout<<endl;
}

int main()
{
    int arr[]={10,15,-5,15,-10,5};
    int size=sizeof(arr)/sizeof(arr[0]);

    int givenSum=55;
    int status=0;

    map<int,int> mp;
    int curr_sum=0;
    for(int i=0;i<size;i++)
    {
        // cout<<"inside loop "<<i<<" times\n";
        curr_sum+=arr[i];
        mp[curr_sum]=i;

        if(curr_sum==givenSum)
        {
            cout<<"Subarray of givenSum is from "<<0<<" to "<<i<<"th index tak\n";    
            break;       
        }

        if(mp.find(curr_sum-givenSum)!=mp.end())
        {
            status=1;
            // cout<<"sunarray founded\n";
            map<int,int>::iterator it;
            it=mp.find(curr_sum-givenSum);
            cout<<"Subarray of givenSum is from "<<it->second<<" to "<<i<<"th index tak\n";
            // break;
        }
    }
    if(status==0)
    {
        cout<<"subarray of givenSum is not present in the given array\n";
    }
    // printMap(mp);

}