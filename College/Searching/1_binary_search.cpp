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

int binary_search(int find_ele, int arr[], int low, int high)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == find_ele)
        {
            return mid;
            cout<<"element "<<find_ele<<" found at:"<<mid<<"position.\n";
        }
        if (arr[mid] > find_ele)
        {
            high = mid - 1;
            return binary_search(find_ele, arr, low, high);
        }
        if (arr[mid] < find_ele)
        {
            low = mid + 1;
            return binary_search(find_ele, arr, low, high);
        }
    }
    return -1;
}
int main()
{
    int arr[] = {12, 23, 34, 56, 67, 78, 89, 99, 111, 222, 333, 444, 555, 666};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    int find_ele=111;
    int search_ele_pos=binary_search(find_ele, arr, 0, size);
    if(search_ele_pos==-1)
    {
        cout<<"OPPS! element "<<find_ele<<" not found!";
    }
    else
    {
        cout<<"position of Element"<<find_ele<<" = "<<search_ele_pos;
    }
}