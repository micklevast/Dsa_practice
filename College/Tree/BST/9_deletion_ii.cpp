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
        left = right = NULL;
    }
};
tnode *deletionAllCase(tnode *root, int del_data);
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
tnode *min_value_node(tnode *ptr)
{
    tnode *pttr = ptr;
    while (pttr && pttr->left != NULL)
    {
        pttr = pttr->left;
    }
    return pttr;
}
tnode *insertion(tnode *root, int insertVal)
{
    if (root == NULL)
    {
        return new tnode(insertVal);
    }
    else
    {
        if (root->data > insertVal)
            root->left = insertion(root->left, insertVal);
        else if (root->data < insertVal)
            root->right = insertion(root->right, insertVal);
        else if (root->data == insertVal)
        {
            cout << "can;t able to insert as same data is already present in these tree\n";
            return NULL;
        }
    }
    return root;
}
tnode *insertion_2(int val, tnode *root)
{
    tnode *prev = NULL;
    if (root == NULL)
    {
        return new tnode(val);
    }
    else
    {
        while (root != NULL)
        {
            prev = root;
            if (root->data > val)
                root = root->left;
            else if (root->data < val)
                root = root->right;
        }
        tnode *insert_node = new tnode(val);
        if (prev->data > val)
            prev->left = insert_node;
        else
            prev->right = insert_node;
    }
    return NULL;
}
//                 236
//                /    \
//               62     90
//              / \    /  \
//             53  70 80     99
//            /  \       /  \
//           0    0     0    300
//
int main()
{
    tnode *root = new tnode(236);
    tnode *a = new tnode(62);
    tnode *b = new tnode(90);
    tnode *c = new tnode(53);
    tnode *d = new tnode(70);
    tnode *e = new tnode(80);
    tnode *f = new tnode(99);
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->left = e;
    b->right = f;
    inorder_traversal(root);

    tnode *min_node = min_value_node(root);
    cout << "\nmin value in tree:" << min_node->data << endl;

    // insertion(root,95);
    //  inorder_traversal(root);

    insertion(root,300);
    inorder_traversal(root); 

    cout << endl;
    root = deletionAllCase(root, 99);
    inorder_traversal(root);

    cout << endl;
    root = deletionAllCase(root, 90);
    inorder_traversal(root);
}

tnode *deletionAllCase(tnode *root, int del_data)
{
    if (root == NULL) //if no such data is found than it is base case
        return root;

    if (root->data > del_data)
        root->left = deletionAllCase(root->left, del_data);
    else if (root->data < del_data)
        root->right = deletionAllCase(root->right, del_data);
    else if (root->data == del_data)
    {
        // 1st case if deldata have zero child
        if (root->left == NULL && root->right == NULL)
            return NULL;

        // 2nd case if deldata have only  one child

        else if (root->left == NULL)
        {
            tnode *del_node = root->right;
            delete root;
            return del_node;
        }
        else if (root->right == NULL)
        {
            tnode *del_node = root->left;
            delete root;
            return del_node;
        }

        //3rd case if deldata ahve two child
        else
        {
            tnode *min_successor = min_value_node(root->right);
            root->data = min_successor->data;

            root->right = deletionAllCase(root->right, min_successor->data);
        }
    }
    return root;
}