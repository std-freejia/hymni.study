#include <iostream>
#include <limits.h>

using namespace std;

struct MST
{
    int minCost;
    int nextNode;
};

const int N_MAX = 1000;

int N = 0;
int min_sum = 0;
int Graph[N_MAX + 1][N_MAX + 1] = { 0 };
MST Nodes[N_MAX + 1] = { 0 };

int MSTPrim(int start_node);

int main(int argc, char* argv[], char* envs[])
{
    int M = 0;
    int node1 = 0;
    int node2 = 0;
    int cost = 0;

    cin >> N;
    cin >> M;

    int i = 0;
    for (i; i < M; i++)
    {
        cin >> node1 >> node2 >> cost;
 
        if(node1 != node2)
        {
            Graph[node1][node2] = cost;
            Graph[node2][node1] = cost;
        }
    }

    int start_node = 1;
    MSTPrim(start_node);

    cout << min_sum << endl;

    return 0;
}

int MSTPrim(int start_node)
{
    int counter = 0;
    int min = 0;
    int node_insert = 0;

    Graph[start_node][start_node] = true;

    counter++;

    int i = 1;
    for (i; i <= N; i++)
    {
        if (Graph[i][start_node] != 0)
        {
            Nodes[i].minCost = Graph[i][start_node];
            Nodes[i].nextNode = start_node;
        }
        else
        {
            Nodes[i].minCost = INT_MAX;
            Nodes[i].nextNode = start_node;
        }
    }

    while (counter < N)
    {
        min = INT_MAX;

        for (i = 1; i <= N; i++)
        {
            if (Graph[i][i] == 0 && Nodes[i].minCost < min)
            {
                node_insert = i;

                min = Nodes[i].minCost;
            }
        }

        Graph[node_insert][node_insert] = true;

        counter++;

        min_sum += min;
        
        for (i = 1; i <= N; i++)
        {
            if (Graph[i][i] == 0 
                && Graph[i][node_insert] != 0 
                && Nodes[i].minCost > Graph[i][node_insert])
            {
                Nodes[i].minCost = Graph[i][node_insert];
                Nodes[i].nextNode = node_insert;
            }
        }
    }

    return 0;
}
