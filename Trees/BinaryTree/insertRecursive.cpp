//Insert into binary tree using recursion 
//That's lit.

#include<iostream>

using namespace std;

struct binaryTree
{
    int data;
    binaryTree* left;
    binaryTree* right;
};

binaryTree* root = NULL;

void insertRecursive(binaryTree* root, int data)
{
    if(root == NULL)
    {
        binaryTree* node = new binaryTree;
        node->left = NULL;
        node->right = NULL;
        node->data = data;
        root = node;
        return;
    }

    if(data < root->data)
    {
        insertRecursive(root->left,data);
    }
    
    if(data>root->data)
    { 
        insertRecursive(root->right,data);
    }
}

void preOrderTraversal(binaryTree* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main()
{
    insertRecursive(root, 10);
    insertRecursive(root, 15);
    insertRecursive(root, 6);
    insertRecursive(root, 12);
    insertRecursive(root, 2);
    insertRecursive(root, 8);
    insertRecursive(root, 18);
    cout<<"Pre Order Traversal is ";preOrderTraversal(root);
    cout<<endl;

}