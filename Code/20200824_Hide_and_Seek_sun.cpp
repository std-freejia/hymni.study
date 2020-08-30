#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_Node = 100001;
vector<int> graph[MAX_Node];
queue<int> node_queue;
int accessed[MAX_Node] = { 0 };
int K = 0;

int init_graph();
int BFS();

int main(int argc, char* argv[], char* envs[])
{
    int N = 0;

    cin >> N >> K;

    init_graph();

    node_queue.push(N);

    BFS();

    return 0;
}

int init_graph()
{
    for (int i = 0; i < MAX_Node; i++)
    {
        if (i - 1 >= 0)
        {
            graph[i].push_back(i - 1);
        }

        if (i + 1 < MAX_Node)
        {
            graph[i].push_back(i + 1);
        }

        if (i * 2 < MAX_Node)
        {
            graph[i].push_back(i * 2);
        }
    }

    return 0;
}

int BFS()
{
    int current_node = 0;
    int steps = 0;

    while (1)
    {
        int size = node_queue.size();

        for (int i = 0; i < size; i++)
        {
            current_node = node_queue.front();

            node_queue.pop();

            accessed[current_node] = 1;

            if (current_node == K)
            {
                cout << steps << endl;

                return 0;
            }

            for (int i = 0; i < graph[current_node].size(); i++)
            {
                if (!accessed[graph[current_node][i]])
                {
                    node_queue.push(graph[current_node][i]);
                }
            }
        }

        steps++;
    }

    return 0;
}
