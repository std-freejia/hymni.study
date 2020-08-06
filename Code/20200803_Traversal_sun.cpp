#include <iostream>

using namespace std;

struct Node
{
    Node* left;
    Node* right;
    char name;
};

Node* new_node(char name);
Node* add_children(Node* tree, char* input);
int preorder(Node* tree);
int inorder(Node* tree);
int postorder(Node* tree);
int destroy_tree(Node** tree);

int main(int argc, char* argv[], char* envs[])
{
    int N = 0;
    char input[3] = { 0 };

    Node* tree = NULL;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> input[0] >> input[1] >> input[2];

        tree = add_children(tree, input);
    }

    preorder(tree);
    cout << endl;

    inorder(tree);
    cout << endl;

    postorder(tree);
    cout << endl;

    destroy_tree(&tree);

    return 0;
}

Node* new_node(char name)
{
    Node* newNode = new Node;

    newNode->name = name;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* add_children(Node* tree, char* input)
{
    if (!tree)
    {
        tree = new_node(input[0]);
    }
    
    if (tree->name == input[0])
    {
        if (input[1] != '.')
        {
            tree->left = new_node(input[1]);
        }

        if (input[2] != '.')
        {
            tree->right = new_node(input[2]);
        }
    }
    else
    {
        if (tree->left)
        {
            tree->left = add_children(tree->left, input);
        }

        if (tree->right)
        {
            tree->right = add_children(tree->right, input);
        }
    }

    return tree;
}

int preorder(Node* tree)
{
    if (tree)
    {
        cout << tree->name;

        preorder(tree->left);

        preorder(tree->right);
    }
    
    return 0;
}

int inorder(Node* tree)
{
    if (tree)
    {
        inorder(tree->left);

        cout << tree->name;

        inorder(tree->right);
    }

    return 0;
}

int postorder(Node* tree)
{
    if (tree)
    {
        postorder(tree->left);

        postorder(tree->right);

        cout << tree->name;
    }

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
