#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100000;

vector<int> edges[MAX_N + 1];
int parents[MAX_N + 1] = { 0 };

int main(int argc, char* argv[], char* envs[])
{
    int N = 0;
    int count = 1;
    int node1 = 0;
    int node2 = 0;

    //cin >> N;
    scanf("%d", &N);

    parents[1] = 1;

    while (count < N)
    {
        //cin >> node1 >> node2;
        scanf("%d %d", &node1, &node2);

        edges[node1].push_back(node2);
        edges[node2].push_back(node1);

        count++;
    }

    int i = 0;
    int j = 0;
    int current = 0;
    queue<int> node_queue;

    node_queue.push(1);

    while (!node_queue.empty())
    {
        current = node_queue.front();

        node_queue.pop();
        
        for (i = 0; i < edges[current].size(); i++)
        {
            if (parents[edges[current][i]] == 0)
            {
                node_queue.push(edges[current][i]);

                parents[edges[current][i]] = current;
            }
        }
    }

    for (i = 2; i <= N; i++)
    {
        //cout << parents[i] << endl;
        printf("%d\n", parents[i]);
    }

    return 0;
}
