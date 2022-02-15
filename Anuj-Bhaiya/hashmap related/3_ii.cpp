#include <iostream>
#include <unordered_map>
using namespace std;
void printMap(unordered_map<int,int> mp)
{
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<" -> "<<it->second<<endl;
    }
    cout<<"------------------------------\n";
}

void detect_distinct_ele_in_windowSize(int arr[], int size, int windowSize)
{
    unordered_map<int, int> Ump;

    // if (Ump.find(5)==Ump.end())
    // cout<<"No element in this map before entering any element in these map:"<<(Ump.find(5))->first<<endl;

    int distinct_ele=0;

    for(int i=0;i<windowSize;i++)
    {
        if(Ump.find(arr[i])==Ump.end())
        {
            Ump[arr[i]]=1;
            distinct_ele++;
        }
        else
        {
            int prev_freq_of_that_ele=Ump[arr[i]];
            Ump[arr[i]]=prev_freq_of_that_ele+1;
        }
    }
cout<<"total distinct element in first window side:"<<distinct_ele<<" [ "<<Ump.size()<<"]\n";
        printMap(Ump);

// slidiing the window
for(int j=windowSize;j<size;j++)
{
    unordered_map<int,int>::iterator it=Ump.find(arr[j-windowSize]);
    if(it->second==1)
    {
        Ump.erase(it);
        distinct_ele--;
    }
    else if(it->second>1)
    {
        Ump[arr[j-windowSize]]=(it->second)-1;
    }

// sliding happen here


    if(Ump.find(arr[j])==Ump.end())
    {
        Ump[arr[j]]=1;
        distinct_ele++;
    }
    else
    {
        int prev_freq_of_that_ele=Ump[arr[j]];
        Ump[arr[j]]=prev_freq_of_that_ele+1;
    }
    cout<<"distinct element in window "<<j-windowSize+2<<" :"<<distinct_ele<<" ["<<Ump.size()<<"]\n";
    printMap(Ump);
}

}

int main()
{
    int window_of_arr[] = {1, 5, 1, 2, 6, 6, 6, 2, 1, 1, 1, 1};
    int size = sizeof(window_of_arr) / sizeof(window_of_arr[0]);
    int window_size = 6;
    detect_distinct_ele_in_windowSize(window_of_arr, size, window_size);
}