#include<iostream>
using namespace std;
class tnode{
    public:
    int data;
    tnode *left;
    tnode *right;
    tnode(int val)
    {
        data=val;
        left=right=NULL;
    }
};
void inordertraversal(tnode *root)
{
    tnode *temp=root;
    if(temp!=NULL)
    {
        inordertraversal(temp->left);
        cout<<temp->data<<" ";
        inordertraversal(temp->right);
    }
}
void insertion(tnode *root,int inData)
{
    if(root==NULL)
    {
        tnode *insertNode=new tnode(inData);
        root=insertNode;
        
    }
    else
    {
        tnode *prev=NULL;
        while(root!=NULL )
        {
            prev=root;
            if(root->data==inData)
            {
                cout<<"we can't insert these data as same data is available in these tree!\n";
                return;
            }
            if(root->data>inData)
            root=root->left;
            else if(root->data<inData)
            root=root->right;
        }
        tnode *insertNode=new tnode(inData);
        
        if(prev->data>inData)
        prev->left=insertNode;
        else
        prev->right=insertNode;

        
    }
}
//                  111
//                /    \
//               80     150
//              / \    /  \
//             50  90 120  180
//            /  \       /  \
//           0    0     0   500
//
int main()
{
    tnode *root=new tnode(111);
    tnode *a=new tnode(80);
    tnode *b=new tnode(150);
    tnode *c=new tnode(50);
    tnode *d=new tnode(90);
    tnode *e=new tnode(120);
    tnode *f=new tnode(180);
    tnode *g=new tnode(500);
    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->left=e;
    b->right=f;
    f->right=g;
    inordertraversal(root);
    cout<<endl;
    insertion(root,200);
    insertion(root,10);
    insertion(root,350);
   inordertraversal(root);
}