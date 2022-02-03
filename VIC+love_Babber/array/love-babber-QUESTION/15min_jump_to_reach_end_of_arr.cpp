#include <iostream>
using namespace std;
int Min_jmp(int arr[], int size)
{
    // if(arr[0]==0)
    // return -1;
    int jmp_index = 0;
    int step_count = 0;
    while (jmp_index < size - 1)
    {
        if (arr[jmp_index] == 0)
            return -1;
        jmp_index += arr[jmp_index];
        step_count++;
    }
    return step_count;
}
int main()
{
    int arr[] = {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min_jmp = Min_jmp(arr, size);
    if(min_jmp==-1)
    cout<<"jumping to end of array in can't achievable\n";
    cout << "min step:" << min_jmp;
}  