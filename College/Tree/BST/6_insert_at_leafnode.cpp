#include <iostream>
using namespace std;
class tnode
{
public:
    int data;
    tnode *left;
    tnode *right;
    tnode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
//                  78
//                /    \
//               65     90
//              / \    /  \
//             53  70 80     99
//            /  \       /  \
//           0    0     0    500
//
void insert_at_leafnode(tnode *root,int val)
{
    tnode *prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(root->data==val)
        {
            cout<<"similar data found can;t able to insert this data!\n";
            return;
        }
        else if(root->data>val)
        {
            root=root->left;
        }
        else
        root=root->right;
    }
    tnode *insert_node=new tnode(val);
    if(prev->data>val)
    {
        cout<<"insert toward left successfully\n";
        prev->left=insert_node;
    }
    else
    {
        cout<<"insert toward right successfully\n";
        prev->right=insert_node;
    }

}
void preorder_traversal(tnode *root)
{
    if(root!=NULL)
    {
        preorder_traversal(root->left);
        cout<<root->data<<" ";
        preorder_traversal(root->right);
    }
}
int main()
{
    tnode *root = new tnode(78);
    tnode *a = new tnode(65);
    tnode *b = new tnode(90);
    tnode *c = new tnode(53);
    tnode *d = new tnode(70);
    tnode *e = new tnode(80);
    tnode *f = new tnode(99);  
    root->left = a;
    root->right = b;
    (*a).left = c; //a ke left ke address me c ka address rakh do
    a->right = d;
    (*b).left = e;
    b->right = f;
    preorder_traversal(root);
    cout<<endl;
    insert_at_leafnode(root,55);
    // cout<<"data found:"<<root->right->right->right->data<<endl;
    preorder_traversal(root);

    insert_at_leafnode(root,75);
     preorder_traversal(root);

    insert_at_leafnode(root,95);
     preorder_traversal(root);
}