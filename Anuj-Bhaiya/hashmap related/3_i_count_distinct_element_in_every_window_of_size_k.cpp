#include<iostream>
#include<unordered_map>
using namespace std;
void print_map(unordered_map<int,int> mp)
{
    unordered_map<int,int>::iterator it;
    for(it= mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<" -> "<<it->second<<endl;
    }
    cout<<"-----------------------------------\n";
}

void counting_distinct_ele_of_Given_window_size(int arr[],int size,int window_size)
{
    unordered_map<int,int> Ump;
    for(int i=0;i<window_size;i++)
    {
        if(Ump[arr[i]]==0)
        {
           Ump[arr[i]]=1; 
        }
        else if(Ump[arr[i]]>=1)
        {
           Ump[arr[i]]+=1; 
        }
    }
    cout<<"dintinct element in first window of size 4:="<<Ump.size()<<endl;
    print_map(Ump);


    for(int j=window_size;j<size;j++)
    {
        // sliding window
        if(Ump[arr[j-window_size]]==1)
        {
            auto it=Ump.find(arr[j-window_size]);
            Ump.erase(it);
        }
        else if(Ump[arr[j-window_size]]>1)
        {
            Ump[arr[j-window_size]]-=1;
        }

        //insert new element in map after sliding
        if(Ump[arr[j]]==0)
        {
           Ump[arr[j]]=1; 
        }
        else if(Ump[arr[j]]>=1)
        {
           Ump.insert({arr[j],Ump[arr[j]]+1}); 
        }
        cout<<"dintinct element in  window of size 4:="<<Ump.size()<<endl;
        print_map(Ump);
    }

}


int main()
{
    
    int arr[]={2,4 ,4,1,2,5,8,5,2,4,1,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    int window_size=4;
    counting_distinct_ele_of_Given_window_size(arr,size,window_size);

}
