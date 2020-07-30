#include <iostream>

using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int key;
};

Node* trees[16] = { 0 };

int build_tree(int level_num);
Node* left_sub(Node* tree);
Node* right_sub(Node* tree);
int preorder(Node* tree);
int destroy_tree(Node** tree);

int main(int argc, char* argv[], char* envs[])
{
    int level_num = 0;
    int index = 0;

    cin >> level_num;

    if (level_num == 1)
    {
        cout << level_num << endl;
    }
    else
    {
        for (index = 2; index <= level_num; index++)
        {
            build_tree(index);
        }

        preorder(trees[level_num]);
    }

    for (index = 2; index <= level_num; index++)
    {
        destroy_tree(&trees[index]);
    }

    return 0;
}

int build_tree(int level_num)
{
    Node* tree = new Node;

    if (level_num == 2)
    {
        tree->key = 1;
        tree->left = new Node;
        tree->right = new Node;

        tree->left->key = 2;
        tree->left->left = NULL;
        tree->left->right = NULL;

        tree->right->key = 3;
        tree->right->left = NULL;
        tree->right->right = NULL;
    }
    else
    {
        tree->key = 1;
        tree->left = left_sub(trees[level_num - 1]);
        tree->right = right_sub(trees[level_num - 1]);
    }

    trees[level_num] = tree;

    return 0;
}

Node* left_sub(Node* tree)
{
    Node* temp = new Node;
    
    if (tree->left != NULL)
    {
        temp->key = tree->key * 2;
        temp->left = left_sub(tree->left);
        temp->right = left_sub(tree->right);
    }
    else
    {
        temp->key = (tree->key) * 2 + 1;
        temp->left = NULL;
        temp->right = NULL;
    }

    return temp;
}

Node* right_sub(Node* tree)
{
    Node* temp = new Node;
    
    if (tree->left != NULL)
    {
        temp->key = (tree->key) * 2 + 1;
        temp->left = right_sub(tree->left);
        temp->right = right_sub(tree->right);
    }
    else
    {
        temp->key = tree->key * 2;
        temp->left = NULL;
        temp->right = NULL;
    }

    return temp;
}

int preorder(Node* tree)
{
    cout << tree->key << " ";

    if (tree->left != NULL)
    {
        preorder(tree->left);
        preorder(tree->right);
    }

    return 0;
}

int destroy_tree(Node** tree)
{
    if ((*tree) != NULL)
    {
        if ((*tree)->left != NULL)
        {
            destroy_tree(&((*tree)->left));
            destroy_tree(&((*tree)->right));
        }

        delete(*tree);

        *tree = NULL;
    }

    return 0;
}
