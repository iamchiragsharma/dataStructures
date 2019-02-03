//To be completed 

#include <iostream>
#include <stack>

using namespace std;

struct binaryTree{
    int data;
    binaryTree* left;
    binaryTree* right;
};

binaryTree* root = NULL;

void postOrderTraversal(binaryTree* root)
{
    if(root == NULL)
        return;
        
    postOrderTraversal(root->left);   
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int main()
{
    
}