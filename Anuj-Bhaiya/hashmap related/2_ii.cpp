#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 1, 0, 1, 1, 0, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    int count_1 = 0, count_0 = 0;
    int final_length_of_sub_array = 0;
    int curr_len_of_subarr=0;
    int start=0,end=0;
    for (int i = 0; i < size; i++)
    {
        // cout<<"vallue of i:"<<i<<endl;
        for (int j = i; j < size; j++)
        {
            // cout<<"inner loop\n";
            if (arr[j] == 0)
                count_0++;
            if (arr[j] == 1)
                count_1++;
            if (count_0 == count_1)
            {
                // cout<<"Subarr start from "<<i<<" end to "<<j<<endl;
                curr_len_of_subarr=j-i+1;
                if(curr_len_of_subarr>final_length_of_sub_array)
                {
                    final_length_of_sub_array=curr_len_of_subarr;
                    start=i;
                    end=j;
                }
            }
        }
        count_0=0;
        count_1=0;
    }
    cout<<"Subarray len:"<<final_length_of_sub_array<<endl;
    cout<<"Subarr start from "<<start<<" end to "<<end<<endl;
}