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
void search_iterative(tnode *root, int search_data)
{
    if (root == NULL)
        cout << "data " << search_data << " not found!\n";
    while (root != NULL)
    {
    
        cout<<"enter in loop\n";
        if (root->data == search_data)
        {
            cout<<"data found range\n";
            cout << "data found:" << search_data << endl;
            break;
        }
        else if (root->data > search_data)
            root = root->left;
        else
            root = root->right;
    }
    //these code will execute only if break; is not executed
    if (root==NULL )
    cout << "data " << search_data << " not found!\n";
}

tnode* search_iter2(tnode *root,int val)
{
    if(root==NULL)
    cout<<"data "<<val<<" not found\n";
    while(root!=NULL)
    {
        if(root->data==val)
        return root;
        else if(root->data>val)
        root=root->left;
        else
        root=root->right;
    }
    return NULL; //if data not found

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
    search_iterative(root, 62);

    tnode *tnd=search_iter2(root,569);
    if(tnd!=NULL)
    cout<<"data "<<tnd->data<<" found\n";
    if(tnd==NULL)
    cout<<"data not founded\n";
}