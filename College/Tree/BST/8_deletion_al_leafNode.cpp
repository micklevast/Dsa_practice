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
//                  75
//                /    \
//               62     90
//              / \    /  \
//             53  69 80   99
//            /  \       /  \
//           0    0     0    10 0
//
void delete_tnode(tnode *root, int del_data)
{
    tnode *prev = NULL;
    if (root != NULL)
    {
        while (root != NULL && root->data != del_data)
        {
            prev = root;
            if (root->data > del_data)
            {
                root = root->left;
            }
            else if (root->data < del_data)
            {
                root = root->right;
            }
        }
        cout << "data " << del_data << " founded\n";

        cout << "root:" << root->data;
        if (prev->left->data == del_data)
            prev->left = NULL;
        else if (prev->right->data == del_data)
            prev->right = NULL;
        // delete root;
        cout << "deletetion success\n";
    }
}
tnode *successor_as_MinValueNode(tnode *root)
{
    tnode *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
tnode *deletion_all_case(tnode *root, int val)
{
    if (root == NULL)
        return root;
    if (val < root->data)
        root->left = deletion_all_case(root->left, val);
    else if (val > root->data)
        root->right = deletion_all_case(root->right, val);
    else if (val == root->data)
    {
        // 1st case if there is no child
        if (root->left == NULL && root->right == NULL)
            return NULL;

        // 2nd case if there is only one child
        else if (root->left == NULL)
        {
            tnode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            tnode *tempp = root->left;
            delete root;
            return tempp;
        }

        // 3rd case if both child of that node is present
        else
        {
            tnode *succ_tnode = successor_as_MinValueNode(root->right);
            root = succ_tnode;
            root->right = deletion_all_case(root->right, succ_tnode->data);
        }
    }
    return root;
}
int main()
{
    tnode *root = new tnode(236);
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
    inorder_traversal(root);
    // delete_tnode(root,99);
    // inorder_traversal(root);

    root = deletion_all_case(root, 80);
    cout << endl;
    inorder_traversal(root);
}