#include<iostream>

using namespace std;

struct binaryTree{
    int data;
    binaryTree* left;
    binaryTree* right;
};

binaryTree* root = NULL;
int maxValue = 0;

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

void maxElement(binaryTree* root)
{
    if(root==NULL)
    {
        return;
    }
    if (root->data > maxValue)
    {
        maxValue = root->data;
    }
    maxElement(root->left);
    maxElement(root->right);
}

/*Max Element without Recursion is same as traversal just instead of printing you have to check
if the value is bigger than the max if yes than assign it to max
2. There is one more thing to do: I can improve the algorithms. 
    Rough Idea: We don't have to traverse whole tree. Maybe we do what who knows?*/


int main()
{
    insertBinaryTree(&root, 10);
    insertBinaryTree(&root, 12);
    insertBinaryTree(&root, 2);
    insertBinaryTree(&root, 15);
    insertBinaryTree(&root, 1);
    maxElement(root);
    cout<<maxValue;
}