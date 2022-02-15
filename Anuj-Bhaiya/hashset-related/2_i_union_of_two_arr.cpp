#include <iostream>
#include <algorithm>
using namespace std;
void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void union_finding(int arr1[], int size1, int size2, int arr2[])
{
    int i = 0, j = 0;
    int arrr[size1 + size2];
    int k = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            if (i == 0)
                arrr[k++] = arr1[i];

            if (arr1[i] != arr1[i - 1] && i != 0)
                arrr[k++] = arr1[i];

            i++;

            cout << "1st con\n";
        }
        else if (arr1[i] > arr2[j])
        {
            if (j == 0)
                arrr[k++] = arr2[j];

            if (arr2[j] != arr2[j - 1] && j != 0)
                arrr[k++] = arr2[j];

            j++;
            cout << "2nd con\n";
        }
        else if (arr1[i] == arr2[j])
        {
            if (arr1[i] != arr1[i - 1] && i != 0)
                arrr[k++] = arr1[i];

            i++;
            j++;
            cout << "3rd con\n";
        }
    }
    if (i >= size1)
    {
        while (j < size2)
        {
            if (arr2[j] != arr2[j - 1] && j != 0)
                arrr[k++] = arr2[j];

            j++;
        }
    }
    if (j >= size2)
    {
        while (i < size1)
        {
            if (arr1[i] != arr1[i - 1] && i != 0)
                arrr[k++] = arr1[i];

            i++;
        }
    }

    cout << "number of element in union of two array(k):" << k << endl
         << "element are:\n";
    for (int i = 0; i < k; i++)
        cout << arrr[i] << " ";

    cout << endl;
}

int main()
{
    int arr1[] = {12, 45, 23, 12};
    int arr2[] = {5, 23, 5, 89};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    sort(arr1, arr1 + size1);
    sort(arr2, arr2 + size2);
    print_arr(arr1, size1);
    print_arr(arr2, size2);

    union_finding(arr1, size1, size2, arr2);
}