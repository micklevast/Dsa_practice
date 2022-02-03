#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};

void preorder_recursive_traversal(node *root)
{
    node *temp=root;
    if(temp!=NULL)
    {
        cout<<temp->data<<" ";
        preorder_recursive_traversal(temp->left);
        preorder_recursive_traversal(temp->right);
       
    }
}

void postorder_traversal(node *root)
{
     node *temp=root;
    if(temp!=NULL)
    {
        preorder_recursive_traversal(temp->left);
        preorder_recursive_traversal(temp->right);
        cout<<temp->data<<" ";
        
    }   
}

void inorder_traversal(node *root)
{
     node *temp=root;
    if(temp!=NULL)
    {
        preorder_recursive_traversal(temp->left);
        cout<<temp->data<<" ";
        preorder_recursive_traversal(temp->right);
        
    }   
}

node *creat_node(int data)
{
    node *new_node = new node;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
//                 452
//              /      \
//            236       963
//          /    \    /     \
//         23    98  49     93
//        /  \
//       55  0
//

int main()
{
    node *root = creat_node(452);
    node *a = creat_node(236);
    node *b = creat_node(963);
    node *c = creat_node(23);
    node *d = creat_node(98);
    node *e = creat_node(49);
    node *f = creat_node(93);
    node *g = creat_node(55);
    root->left = a;
    root->right = b;
    a->left=c;
    a->right=d;
    b->left=e;
    b->right=f;
    c->left=g;
    cout<<"Preorder Tree traversasl:";
    preorder_recursive_traversal(root);
    cout<<"\nInorder Tree Traversal:";
    inorder_traversal(root);
    cout<<"\nPostorder Tree Traversal:";
    postorder_traversal(root);
}