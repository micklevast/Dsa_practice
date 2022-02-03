#include<iostream>
#include<windows.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};

void preorder_recursive_traversal(node *root)
{
    node *temp=root;
    if(temp!=NULL)
    {
        cout<<temp->data<<" ";
        preorder_recursive_traversal(temp->left);
        preorder_recursive_traversal(temp->right);
        Sleep(100);
    }
}

void postorder_traversal(node *root)
{
     node *temp=root;
    if(temp!=NULL)
    {
        preorder_recursive_traversal(temp->left);
        preorder_recursive_traversal(temp->right);
        cout<<temp->data<<" ";
        Sleep(100);
    }   
}

void inorder_traversal(node *root)
{ 
    char name[20];
    cin>>name;
     node *temp=root;
    if(temp!=NULL)
    {
        preorder_recursive_traversal(temp->left);
        cout<<temp->data<<" ";
        preorder_recursive_traversal(temp->right);
        Sleep(100);
    }   
}
//                 6565
//              /      \
//            2369       9632
//          /    \    /     \
//         23    98  49     93
//        /  \
//       55  0
//
int main()
{
    node *root,*a,*b;
    root=new node;
    a=new node;
    b=new node;

    root->data=6565;
    root->left=NULL;
    root->right=NULL;

    a->data=2369;
    a->left=NULL;
    a->right=NULL;

    b->data=9632;
    b->left=NULL;
    b->right=NULL;

    root->left=a;
    root->right=b;

    cout<<"\npreorder traversal:";
    preorder_recursive_traversal(root);
    cout<<"\npostorder traversal:";
    postorder_traversal(root);
    cout<<"\ninorder traversal:";
    inorder_traversal(root);
}