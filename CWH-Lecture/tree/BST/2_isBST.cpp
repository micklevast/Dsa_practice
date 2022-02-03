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
void inorder_traversal(tnode *root)
{
    tnode *temp = root;
    if (temp != NULL)
    {
        inorder_traversal(temp->left);
        cout << temp->data << " ";
        inorder_traversal(temp->right);
    }
}
//                  78
//                /    \
//               62     90
//              / \    /  \
//             53  69 80     99
//            /  \       /  \
//           0    0     0     0
//
void isBST(tnode *root,  int &f)
{

    if (root == NULL)
    return; //check ki root=null h to yhi se return kar do
    static tnode *prev=NULL; //static banaya so that sirf ek bar hi NULL kar sake
    isBST(root->left,  f);
    {
        if (prev != NULL && root->data <= prev->data)
        {
            f = 0;//if f=0 ho gya to yhi se break kar do
            return;
        } 
    }
    prev = root;
    isBST(root->right, f);
}



int main()
{
    tnode *root = new tnode(78);
    tnode *a = new tnode(62);
    tnode *b = new tnode(90);
    tnode *c = new tnode(53);
    tnode *d = new tnode(629);
    tnode *e = new tnode(80);
    tnode *f = new tnode(99);
    root->left = a;
    root->right = b;
    (*a).left = c; //a ke left ke address me c ka address rakh do
    a->right = d;
    (*b).left = e;
    b->right = f;
    cout << "if on inorder traverasal it gives an sorted array ten it must be A BST\n";
    inorder_traversal(root);
int k=1;
isBST(root,k);
if(k==0)
cout<<"this  is not BST\n";
else
cout<<"this is a BSt\n";
    
    
}