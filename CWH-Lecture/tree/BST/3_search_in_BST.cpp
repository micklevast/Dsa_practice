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
//           0    0     0     0
//
tnode* search_recur(tnode *root, int search_data)
{
    if(root==NULL)
    return NULL;
    if(root->data==search_data)
    return root;
    if(root->data>search_data)
    search_recur(root->left,search_data);
    else //if(root->data<search_data)
    search_recur(root->right,search_data);

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
    tnode *search_node=search_recur(root,53);
    if(search_node!=NULL)
    cout<<"data found:"<<search_node->data<<endl;
    else
    cout<<"data "<<" not found!\n";
}