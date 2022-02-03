// search iteratevely
#include <iostream>
using namespace std;
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int binary_search_method1(int arr[], int l, int r, int find_ele)
{
    int mid = (l + r) / 2;
    while (l <= r && arr[mid] != find_ele)
    {
        if (arr[mid] > find_ele)
        {
            r = mid - 1;
        }
        if (arr[mid] < find_ele)
        {
            l = mid + 1;
        }
        mid = (l + r) / 2;
    }
    if (arr[mid] == find_ele)
        return mid;
    else
        return -1;
}

int binary_search_method2(int arr[], int l, int r, int find_ele)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == find_ele)
            return mid;
        else if (arr[mid] < find_ele)
            l = mid + 1;
        else if (arr[mid] > find_ele)
            r = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {12, 23, 34, 56, 67, 78, 89, 99, 111, 222, 333, 444, 555, 666};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    int find_ele = 666;
    // int search_1_ele_pos = binary_search_method1(arr, 0, size, find_ele);
    // if (search_ele_pos == -1)
    // {
    //     cout << "OPPS! element " << find_ele << " not found!";
    // }
    // else
    // {
    //     cout << "position of Element " << find_ele << " = " << search_1_ele_pos;
    // }
    int search_2_ele_pos = binary_search_method2(arr, 0, size, find_ele);
    if (search_2_ele_pos == -1)
    {
        cout << "OPPS! element " << find_ele << " not found!";
    }
    else
    {
        cout << "position of Element " << find_ele << " = " << search_2_ele_pos;
    }
}