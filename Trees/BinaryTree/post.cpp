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

void insertBinaryTree(binaryTree** root, int value)
{
    binaryTree* newNode = new binaryTree;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if(*root == NULL)
    {
        *root = newNode;
        return;
    }

    binaryTree* current = *root;

    while(1)
    {
        if(value < current->data)
        {
            if(current->left == NULL)
                break;
            else current = current->left;
        }

        else
        {
            if(current->right == NULL)
                break;
            else current = current->right;
        }

    }

    if(value < current->data)
        current->left = newNode;        
    else current -> right = newNode;

}

void postOrderTraversal(binaryTree* root)
{
    if(root == NULL)
        return;
        
    postOrderTraversal(root->left);   
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void postOrderWithoutRecursion(binaryTree* root)
{
    stack <binaryTree*> postOrder;
    binaryTree* node = root;
    binaryTree* printNode;
    postOrder.push(node);
    while(!postOrder.empty())
    {

        node = postOrder.top();

        if(node->right != NULL)
        {
            postOrder.push(node->right);   
        }
        if(node->left != NULL)
        {
            postOrder.push(node->left);
        }

        
        
    }
}

int main()
{

    insertBinaryTree(&root, 10);
    insertBinaryTree(&root, 15);
    insertBinaryTree(&root, 6);
    insertBinaryTree(&root, 12);
    insertBinaryTree(&root, 2);
    insertBinaryTree(&root, 8);
    insertBinaryTree(&root, 18);
    postOrderTraversal(root);
    cout<<endl;
    postOrderWithoutRecursion(root);
    cout<<endl;
    
}