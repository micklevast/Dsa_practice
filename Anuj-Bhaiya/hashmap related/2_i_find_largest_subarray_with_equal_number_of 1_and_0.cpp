#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    int arr[]={1,1,0,1,1,0,0};
    int size=sizeof(arr)/sizeof(arr[0]);

    unordered_map<int,int> mp;
    int curr_sum=0;
    int length_of_sub_array=0;

    //change 0 to -1 and now original question is trasform into find_largest_subarray_of givenSum=0
    for(int i=0;i<size;i++)
    {
        if(arr[i]==0)
        arr[i]=(-1); //replace 0 by -1
    }


int start=0,end=0;
int len_of_subarr=0;
int curr_len=0;
int final_start=0,final_end=0;
    for(int i=0;i<size;i++)
    {
        curr_sum+=arr[i];
        if(mp.find(curr_sum)!=mp.end())
        {
            cout<<"subarray founded\n";
            unordered_map<int,int>::iterator it;
            it=mp.find(curr_sum);
            start=(it->second)+1;
            end=i;
            curr_len=end-start+1;
            cout<<"subarray start "<<start<<" end to "<<end<<"have len:"<<curr_len<<endl;
            if(curr_len>len_of_subarr)
            {
                final_start=start;
                final_end=end;
                len_of_subarr=curr_len;
            }
        }

        mp[curr_sum]=i;

    }

    cout<<"length of subarray:"<<len_of_subarr<<endl;

}