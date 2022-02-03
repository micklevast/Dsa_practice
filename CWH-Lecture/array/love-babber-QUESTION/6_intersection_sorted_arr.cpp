#include <iostream>
using namespace std;
void intersection_of_sorted_array(int *arr1, int *arr2, int n1, int n2)
{
    int *intersection_Arr = new int(n1 + n2);
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else if (arr1[i] == arr2[j])
        {
            intersection_Arr[k++] = arr1[i];
            i++;
            j++;
        }
    }
    cout<<"n1="<<n1<<"  n2="<<n2<<"  union-array_contain="<<k<<" element" <<endl;
    cout << "union of two array:";
    for (int x = 0; x < k; x++)
    {
        cout << intersection_Arr[x] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[] = {1, 3, 5, 6, 7, 8, 9, 15, 20, 26, 38};
    int arr2[] = {3, 6, 7, 8, 15, 26, 40, 48, 50, 59};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    intersection_of_sorted_array(arr1, arr2, size1, size2);
   
}