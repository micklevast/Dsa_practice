#include <iostream>
#include <map>
// multimap is included in header file #include<map> itself

// Multimap is similar to a map with the addition that multiple elements can have the same keys.
//  Also, it is NOT required that the key-value and mapped value pair have to be unique in this case.
//   One important thing to note about multimap is that multimap keeps all the keys in sorted order always.
//    These properties of multimap make it very much useful in competitive programming.

// The multimap::lower_bound(k) is a built-in function in C++ STL which returns an iterator pointing to the key
//  in the container which is equivalent to k passed in the parameter. In case k is not present in the multimap
//   container, the function returns an iterator pointing to the immediate next element which is just greater 
//   than k. If the key passed in the parameter exceeds the maximum key in the container, 
//   then the iterator returned points to key+1 and element = 0.
// Syntax: ==>multimap_name.lower_bound(key)
// multimap_name.lower_bound(key)



using namespace std;
int main()
{
    int arr[] = {0,0,1,1,0};
    int size = sizeof(arr) / sizeof(arr[0]);

    multimap<int, int> mp; // multimap can take same multiple key in sorted order which is not happen in normal map

    // change 0 to -1 and now original question is trasform into find_largest_subarray_of givenSum=0
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
            arr[i] = (-1); // replace 0 by -1
    }
    int curr_sum = 0;
    int length_of_sub_array = 0;
    int start = 0, end = 0;
    int len_of_subarr = 0;
    int curr_len = 0;
    int final_start = 0, final_end = 0;
    for (int i = 0; i < size; i++)
    {
        curr_sum += arr[i];

        if (mp.find(curr_sum) != mp.end())
        {
            cout << "subarr with sum=0 founded\n";
            start=(mp.lower_bound(curr_sum))->second;
            end=i;
            curr_len=end-start;
            if(curr_len>len_of_subarr)
            {
                len_of_subarr=curr_len;
                final_start=start+1;
                final_end=end;
                cout<<"subarr start from "<<final_start<<" to "<<final_end<<" with len:"<<len_of_subarr<<endl;
            }
        }

        mp.insert(pair<int,int>(curr_sum,i));
        // OR
        // mp.insert({curr_sum,i})
    }

    for(auto it:mp)
    cout<<it.first<<" -> "<<it.second<<endl;


    cout<<"subarr start from "<<final_start<<" to "<<final_end<<" with len:"<<len_of_subarr<<endl;
}