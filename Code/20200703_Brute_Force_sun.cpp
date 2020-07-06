#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int n = 0;  // map size
int shortest_len = 0;
vector<int> shortest_path;

int search_path(int** map, int start_row, int start_col, int current_len, vector<int> current_path);

int main(int argc, char* argv[], char* env[])
{
	cin>>n;

	int** map = (int**)malloc(sizeof(int*)*n);

	for(int i=0; i<n; i++)
	{
		map[i] = (int*)malloc(sizeof(int)*n);
	}

	for(int row=0; row<n; row++)
	{
		for(int col=0; col<n; col++)
		{
			cin>>map[row][col];
		}
	}

	int start_row = 0;
	int start_col = 0;
	int current_len = 0;
	vector<int> current_path;

	search_path(map, start_row, start_col, current_len, current_path);

	cout<<shortest_len<<endl;

	for(int i=0; i<shortest_path.size(); i++)
	{
		cout<<shortest_path[i]<<" ";
	}

	cout<<endl;
	
	return 0;
}

int search_path(int** map, int start_row, int start_col, int current_len, vector<int> current_path)
{
	current_len += map[start_row][start_col];

	current_path.push_back(map[start_row][start_col]);

	if(start_row == n-1 && start_col == n-1)
	{
		if(current_len > shortest_len)
		{
			shortest_len = current_len;

			shortest_path = current_path;
		}

		return 0;
	}
	
	if(start_row + 1 < n)
	{
		search_path(map, start_row+1, start_col, current_len, current_path);
	}

	if(start_col + 1 < n)
	{
		search_path(map, start_row, start_col+1, current_len, current_path);
	}
}
