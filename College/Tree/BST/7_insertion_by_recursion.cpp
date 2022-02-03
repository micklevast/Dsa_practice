#include <iostream>
using namespace std;
class tnode
{
public:
    int data;
    tnode *left;
    tnode *right;
    tnode(){};
    tnode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
tnode *insertion(tnode *root, int insert_data)
{
    if (root == NULL)
    {
        return (new tnode(insert_data));
    }
    if(root->data==insert_data)
    {
        cout<<"can't able to insert new data "<<insert_data <<" as same data is already present in tree!\n";
        return NULL;
    }

    if (root->data > insert_data)
    {
        root->left = insertion(root->left, insert_data);
    }
    if(root->data<insert_data)
    {
        root->right=insertion(root->right,insert_data);
    }
    return root;
}
void inorder_traversal(tnode *root)
{
    if(root!=NULL)
    {
        inorder_traversal(root->left);
        cout<<root->data<<" ";
        inorder_traversal(root->right);
    }
}

int main()
{
    tnode *root=NULL;
    root=insertion(root,50);
    insertion(root,30);
    insertion(root,20);
    insertion(root,40);
    insertion(root,70);
    insertion(root,60);
    insertion(root,80);

    insertion(root,20);

    inorder_traversal(root);

}