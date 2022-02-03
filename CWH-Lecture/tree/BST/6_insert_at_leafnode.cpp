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
//               62     90
//              / \    /  \
//             53  69 80     99
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
        cout<<"insert successfully\n";
        prev->left=insert_node;
    }
    else
    {
        cout<<"insert successfully\n";
        prev->right=insert_node;
    }

}
void preorder_traversal(tnode *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}
int main()
{
    tnode *root = new tnode(78);
    tnode *a = new tnode(62);
    tnode *b = new tnode(90);
    tnode *c = new tnode(53);
    tnode *d = new tnode(62);
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
    insert_at_leafnode(root,60);
    cout<<"data found:"<<root->right->right->right->data<<endl;
    preorder_traversal(root);
}