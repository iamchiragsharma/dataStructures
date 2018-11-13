#include<iostream>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* root = NULL;

void insertTree(node** root, int data)
{
    node* newNode = new node;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    if(*root == NULL)
    {
        *root = newNode;
        return;
    }
    
    node* current = *root;
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

void postOrderTraversal(node* Node)
{
    if(Node == NULL)
    return;

    postOrderTraversal(Node->left);   
    postOrderTraversal(Node->right);
    cout<<Node->data<<" ";

}

int main()
{
    insertTree(&root, 10);
    insertTree(&root, 12);
    insertTree(&root, 2);
    postOrderTraversal(root);
}