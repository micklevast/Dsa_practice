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
tnode* RightMin(tnode *node)
{
    while(node!=NULL && node->left!=NULL)
    {
        node=node->left;
    }
    return node;
}
tnode* deletion(tnode *root,int delData)
{
    if(root==NULL)
    return NULL;
    if(delData<root->data)
    root->left=deletion(root->left,delData);
    else if(delData>root->data)
    root->right=deletion(root->right,delData);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            tnode *temp=root;
            root=root->right;
            delete temp;
            return root;
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            tnode *temp=root;
            root=root->left;
            delete temp;
            return root;
        }
        else
        {
            tnode *rightminNode=RightMin(root->right);
            root->data=rightminNode->data;
            root->right=deletion(root->right,rightminNode->data);
        }
    }
    return root;
}
//                  78
//                /    \
//               62     90
//              / \    /  \
//             53  69 80     99
//            /  \       /  \
//           30    0     0     110
//
int main()
{
    tnode *root = new tnode(78);
    tnode *a = new tnode(62);
    tnode *b = new tnode(90);
    tnode *c = new tnode(53);
    tnode *d = new tnode(69);
    tnode *e = new tnode(80);
    tnode *f = new tnode(99);
    tnode *g=new tnode(30);
    tnode *h=new tnode(110);
    root->left = a;
    root->right = b;
    (*a).left = c; //a ke left ke address me c ka address rakh do
    a->right = d;
    (*b).left = e;
    b->right = f;
    c->left=g;
    f->right=h;
    inorder_traversal(root);
    // deletion(root,110);
    // cout<<endl;
    // inorder_traversal(root);
    //     deletion(root,99);
    // cout<<endl;
    // inorder_traversal(root);
    //     deletion(root,80);
    // cout<<endl;
    // inorder_traversal(root);
    //     deletion(root,62);
    // cout<<endl;
    // inorder_traversal(root);
            deletion(root,78);
    cout<<endl;
    inorder_traversal(root);
    
}