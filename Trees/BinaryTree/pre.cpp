//Binary Tree PreOrder Recursion and PreOrder Without Recursion

#include<iostream>
#include<stack>

using namespace std;

struct binaryTree{
    int data;
    binaryTree* left;
    binaryTree* right;
};

binaryTree* root = NULL;

void insertBinaryTree(binaryTree** root, int data)
{
    binaryTree* newNode = new binaryTree;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    if(*root == NULL)
    {
        *root = newNode;
        return;
    }
    
    binaryTree* current = *root;
    
    while(1)
    {
        if(data < current->data)
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
    if(data<current->data)
        current->left = newNode;
    else current->right = newNode;
}

void preOrderTraversal(binaryTree* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void preOrderWithoutRecursion(binaryTree* root)
{
    stack <binaryTree*> preOrder;
    binaryTree* node = root;
    preOrder.push(node);
    while(!preOrder.empty())
    {
        node = preOrder.top();
        preOrder.pop();
        cout<<node->data<<" ";
        if(node->right != NULL)
        {
            preOrder.push(node->right);
        }
        if(node->left != NULL)
        {
            preOrder.push(node->left);
        }
    }
}

int main()
{
    insertBinaryTree(&root, 10);
    insertBinaryTree(&root, 12);
    insertBinaryTree(&root, 2);
    insertBinaryTree(&root, 15);
    insertBinaryTree(&root, 1);
    cout<<"Pre Order Traversal is ";preOrderTraversal(root);
    cout<<endl;
    cout<<"Pre Order Without Recursion is ";preOrderWithoutRecursion(root);
    cout<<endl;
}