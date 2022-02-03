#include<iostream>
using namespace std;
class tnode{
    public:
    int  data;
    tnode *left;
    tnode *right;
    tnode(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
void inorder_traversal(tnode *root)
{
    tnode *temp=root;
    if(temp!=NULL)
    {
        inorder_traversal(temp->left);
        cout<<temp->data<<" ";
        inorder_traversal(temp->right);
    }
}
//                  78
//                /    \
//               23    89
//              / \    /  \
//             46  91 63   29
//            /  \       /  \
//           0    0     0     0
// 
int main()
{
    tnode *root=new tnode(78);
    tnode *a=new tnode(23);
    tnode *b=new tnode(89);
    tnode *c=new tnode(46);
    tnode *d=new tnode(91);
    tnode *e=new tnode(63);
    tnode *f=new tnode(29);
    root->left=a;
    root->right=b;
    (*a).left=c; //a ke left ke address me c ka address rakh do
    a->right=d;
    (*b).left=e;
    b->right=f;
    inorder_traversal(root);
}