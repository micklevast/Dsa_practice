#include <iostream>
using namespace std;
int arr[20] = {0};
void set_root(int data)
{
    if(arr[0]!=0)
    cout<<"tree already has exit root\n";
    else
    {
        arr[0]=data;
    }
}
void set_left_tree(int val, int parent)
{
    if (arr[parent] == 0)
    {
        cout << "can't insert these " << 2*parent+1 <<" child as parent "<< " not found\n";
    }
    else
    {
        arr[2 * parent + 1] = val;
    }
}

void set_right_tree(int val, int parent)
{
        if (arr[parent] == 0)
    {
       cout << "can't insert these " << 2*parent+2 <<" child as parent "<< " not found\n";
    }
    else
    {
        arr[2 * parent + 2] = val;
    }
}
void tree_traversal(int *arr)
{
    for (int i = 0; i < 20; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    set_root(500);
    set_left_tree(80, 0);
    set_right_tree(70, 0);
    set_left_tree(33,1);
    set_right_tree(500040, 1);
    set_right_tree(40, 3);
    set_left_tree(88,2);
    set_left_tree(66,4);
    set_left_tree(235,6);
    set_right_tree(940, 7);
    tree_traversal(arr);
}