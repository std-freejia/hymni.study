#include <iostream>

using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int key;
};

Node* add_node(int key);
Node* insert(Node* tree, Node* new_node);
int postorder(Node* tree);
int destroy_tree(Node** tree);

int main(int argc, char* argv[], char* envs[])
{
    int key = 0;

    Node* tree = NULL;

    while (cin >> key)
    {
        tree = insert(tree, add_node(key));
    }

    postorder(tree);

    destroy_tree(&tree);

    return 0;
}

Node* add_node(int key)
{
    Node* new_node = new Node;

    new_node->left = NULL;
    new_node->right = NULL;
    new_node->key = key;

    return new_node;
}

Node* insert(Node* tree, Node* new_node)
{
    if (tree == NULL)
    {
        return new_node;
    }

    if (new_node->key < tree->key)
    {
        tree->left = insert(tree->left, new_node);
    }
    else if (new_node->key > tree->key)
    {
        tree->right = insert(tree->right, new_node);
    }

    return tree;
}

int postorder(Node* tree)
{
    if (tree->left)
    {
        postorder(tree->left);
    }

    if (tree->right)
    {
        postorder(tree->right);
    }

    cout << tree->key << endl;

    return 0;
}

int destroy_tree(Node** tree)
{
    if (*tree)
    {
        if ((*tree)->left)
        {
            destroy_tree(&((*tree)->left));
        }

        if ((*tree)->right)
        {
            destroy_tree(&((*tree)->right));
        }

        delete(*tree);

        *tree = NULL;
    }
    
    return 0;
}
