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
void isBST(tnode *root, tnode *&prev, int &f)
{

    if (root == NULL)
        return; //check ki root=null h to yhi se return kar do
    // static tnode *prev=NULL; //static banaya so that sirf ek bar hi NULL kar sake
    isBST(root->left, prev, f);
    {
        if (prev != NULL && root->data <= prev->data)
        {
            f = 0;
            return;
        } //if f=0 ho gya to yhi se break kar do
    }

    prev = root;
    isBST(root->right, prev, f);
}
bool check_bst(tnode *root)
{
    int f = 1;
    tnode *prev = NULL;
    isBST(root, prev, f);
    cout << "F:" << f << endl;
    return f;
}

int main()
{
    tnode *root = new tnode(78);
    tnode *a = new tnode(62);
    tnode *b = new tnode(90);
    tnode *c = new tnode(53);
    tnode *d = new tnode(69);
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

    cout << "isBST:" << check_bst(root);
    ;
}