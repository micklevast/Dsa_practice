#include <bits/stdc++.h>

using namespace std;
 

struct node {

    int key;

    struct node *left, *right;
};
 
// A utility function to create a new BST node

struct node* newNode(int item)
{

    struct node* temp

        = (struct node*)malloc(sizeof(struct node));

    temp->key = item;

    temp->left = temp->right = NULL;

    return temp;
}
 
// A utility function to do 
// inorder traversal of BST

void inorder(struct node* root)
{

    if (root != NULL) {

        inorder(root->left);

        cout << root->key<<" ";

        inorder(root->right);

    }
}
 
/* Given a non-empty binary search tree, return the node
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */

struct node* minValueNode(struct node* node)
{

    struct node* current = node;
 

    /* loop down to find the leftmost leaf */

    while (current && current->left != NULL)

        current = current->left;
 

    return current;
}
 
/* Given a binary search tree and a key, this function
deletes the key and returns the new root */

struct node* deleteNode(struct node* root, int key)
{

    // base case

    if (root == NULL)

        return root;
 

    // If the key to be deleted is 

    // smaller than the root's

    // key, then it lies in left subtree

    if (key < root->key)

        root->left = deleteNode(root->left, key);
 

    // If the key to be deleted is

    // greater than the root's

    // key, then it lies in right subtree

    else if (key > root->key)

        root->right = deleteNode(root->right, key);
 

    // if key is same as root's key, then This is the node

    // to be deleted

    else {

        // node has no child

        if (root->left==NULL and root->right==NULL)

            return NULL;

       

        // node with only one child or no child

        else if (root->left == NULL) {

            struct node* temp = root->right;

            free(root);

            return temp;

        }

        else if (root->right == NULL) {

            struct node* temp = root->left;

            free(root);

            return temp;

        }
 

        // node with two children: Get the inorder successor

        // (smallest in the right subtree)

        struct node* temp = minValueNode(root->right);
 

        // Copy the inorder successor's content to this node

        root->key = temp->key;
 

        // Delete the inorder successor

        root->right = deleteNode(root->right, temp->key);

    }

    return root;
}
 
// Driver Code

int main()
{
  node *root=newNode(200);
  node *a=newNode(100);
  node *b=newNode(225);
  node *c=newNode(75);
  node *d=newNode(150);
  node *e=newNode(210);
  node *f=newNode(250);
  node *g=newNode(300);
  root->left=a;
  root->right=b;
  a->left=c;
  a->right=d;
  b->left=e;
  b->right=f;
  f->right=g;
    inorder(root);
    cout<<endl;

    // deleteNode(root,150);
    // inorder(root);
    // cout<<endl;

    //     deleteNode(root,210);
    // inorder(root);
    // cout<<endl;

    //     deleteNode(root,300);
    // inorder(root);
    // cout<<endl;

        deleteNode(root,200);
    inorder(root);
    cout<<endl;

}