#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int id = 0;
    struct Node* lchild = NULL;
    struct Node* rchild = NULL;
};

int build_tree(Node** tree, vector<int> access_order);
int print_tree(Node* tree);
int destroy_tree(Node** tree);

int main(int argc, char* argv[], char* envs[])
{
    int k = 0;  // the height of tree

    cin >> k;

    int nodes_num = (1 << k) - 1;  // the number of nodes

    vector<int> access_order(nodes_num, 0);

    for (int i = 0; i < nodes_num; i++)
    {
        cin >> access_order[i];
    }

    Node* root = new Node();

    build_tree(&root, access_order);

    print_tree(root);

    destroy_tree(&root);

    return 0;
}

int build_tree(Node** tree, vector<int> access_order)
{
    int subvector_len = access_order.size() / 2;

    (*tree)->id = access_order[subvector_len];

    if (access_order.size() == 1)
    {
        return 0;
    }
    else
    {
        vector<int> split_access_order(subvector_len, 0);

        (*tree)->lchild = new Node();
        (*tree)->rchild = new Node();

        split_access_order.assign(access_order.begin(), access_order.begin() + subvector_len);
        build_tree(&((*tree)->lchild), split_access_order);

        split_access_order.assign(access_order.begin() + subvector_len + 1, access_order.end());
        build_tree(&((*tree)->rchild), split_access_order);
    }
}

int print_tree(Node* tree)
{
    queue<Node*> node_queue;
    vector<int> id_queue;

    Node* p = NULL;

    node_queue.push(tree);

    while (!node_queue.empty())
    {
        p = node_queue.front();

        id_queue.push_back(p->id);

        node_queue.pop();

        if (p->lchild != NULL)
        {
            node_queue.push(p->lchild);
            node_queue.push(p->rchild);
        }
    }

    int level = 1;

    for (unsigned int i = 0; i < id_queue.size(); i++)
    {
        cout << id_queue[i] << " ";

        if ((i + 1) == ((1 << level) - 1))
        {
            cout << endl;

            level++;
        }
    }

    return 0;
}

int destroy_tree(Node** tree)
{
    if (*tree)
    {
        if ((*tree)->lchild)
        {
            destroy_tree(&((*tree)->lchild));
        }

        if ((*tree)->rchild)
        {
            destroy_tree(&((*tree)->rchild));
        }

        delete(*tree);

        *tree = NULL;
    }

    return 0;
}
