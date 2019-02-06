#include<iostream>
#include<queue>

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
    if(data < current->data)
        current->left = newNode;
    else current->right = newNode;
}

void levelOrderWithoutRecursion(binaryTree* root)
{
    queue <binaryTree*> levelOrder;
    binaryTree* node = root;
    levelOrder.push(node);
    while(!levelOrder.empty())
    {
        node = levelOrder.front();
        levelOrder.pop();
        cout<<node->data<<" ";
        if(node->left != NULL)
        {
            levelOrder.push(node->left);
        }
        if(node->right != NULL)
        {
            levelOrder.push(node->right);
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
    levelOrderWithoutRecursion(root);
}
