#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_Node = 1000;
vector<int> map[MAX_Node + 1];
queue<int> adj_node;
int accessed[MAX_Node + 1] = { 0 };

int DFS(int start);
int BFS();

int main(int argc, char* argv[], char* envs[])
{
    int N = 0;
    int M = 0;
    int V = 0;
    int node_1 = 0;
    int node_2 = 0;

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        cin >> node_1 >> node_2;

        map[node_1].push_back(node_2);
        map[node_2].push_back(node_1);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(map[i].begin(), map[i].end());
    }

    DFS(V);

    cout << endl;

    memset(accessed, 0, sizeof(accessed));

    adj_node.push(V);

    BFS();

    return 0;
}

int DFS(int start)
{
    if (accessed[start] == 1)
    {
        return 0;
    }

    accessed[start] = 1;

    cout << start << " ";

    for (int i = 0; i < map[start].size(); i++)
    {
        DFS(map[start][i]);
    }

    return 0;
}

int BFS()
{
    while (!adj_node.empty())
    {
        int current_node = adj_node.front();

        adj_node.pop();

        if (accessed[current_node] == 1)
        {
            continue;
        }

        cout << current_node << " ";

        accessed[current_node] = 1;

        for (int i = 0; i < map[current_node].size(); i++)
        {
            adj_node.push(map[current_node][i]);
        }
    }

    return 0;
}
