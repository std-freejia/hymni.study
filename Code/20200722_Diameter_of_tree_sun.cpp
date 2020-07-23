#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
	int next_node;
	int weight;
};

const int MAX = 10000;
const int root = 1;
int node_num = 0;
int diameter = 0;
int path[MAX + 1] = { 0 };
vector<Edge> Tree_nodes[MAX + 1];

int find_diameter();
int bfs(int node);

int main(int argc, char* argv[], char* envs[])
{
	int start = 0;
	int end = 0;
	int weight = 0;

	Edge edge;

	cin >> node_num;

	for (int i = 1; i < node_num; i++)
	{
		cin >> start >> end >> weight;

		edge = { end, weight };
		Tree_nodes[start].push_back(edge);

		edge = { start, weight };
		Tree_nodes[end].push_back(edge);
	}

	find_diameter();

	return 0;
}

int find_diameter()
{
	// search from root
	int start_node = bfs(root);

	int end_nodr = bfs(start_node);

	cout << diameter << endl;

	return 0;
}

int bfs(int node)
{
	int target_node = 0;
	int current_node = 0;
	int index = 0;  // for loop

	queue<int> node_queue;

	for (index = 0; index <= node_num; index++)
	{
		path[index] = -1;
	}

	node_queue.push(node);

	path[node] = 0;

	while (!node_queue.empty())
	{
		current_node = node_queue.front();

		node_queue.pop();

		for (index = 0; index < Tree_nodes[current_node].size(); index++)
		{
			Edge edge = Tree_nodes[current_node][index];
			
			if (path[edge.next_node] == -1)
			{
				path[edge.next_node] = path[current_node] + edge.weight;

				node_queue.push(edge.next_node);

				if (path[edge.next_node] > diameter)
				{
					diameter = path[edge.next_node];

					target_node = edge.next_node;
				}
			}
		}
	}

	return target_node;
}
