#include <iostream>
using namespace std;
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int partition(int arr[], int low, int high);

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot=arr[low]; //taking pivot elemetn as mid element
    int i=low;
    int j=high;
    while(i<j)
    {
        while(arr[i]<=pivot)i++;
        while(arr[j]>pivot)j--;
        if(i<j)
        swap(arr[i],arr[j]);
    }

    swap(arr[j],arr[low]);
    return (j);
}
int main()
{
    int arr[] = {45, 12, 535, 122, 89, 55557, 919, 68};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    quick_sort(arr, 0, size - 1);
    display(arr, size);
}