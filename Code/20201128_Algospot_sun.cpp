#include <iostream>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

struct pos
{
    int row;
    int col;
};

const int MAX = 100;
int N = 0;
int M = 0;
int diff_dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int visited[MAX][MAX] = {0};
vector<string> maze;
deque<pos> bfs_q;

int BFS();

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s = " ";
    
    cin>>M>>N;
    
    for(int i=0; i<N; i++)
    {
        cin>>s;
        
        maze.push_back(s);
    }
    
    BFS();
    
    return 0;
}

int BFS()
{
    int i = 0;  // for loop
    pos curr = {0, 0};
    pos next = {0, 0};
    
    bfs_q.push_back({0, 0});
    visited[0][0] = 1;
    
    while(!bfs_q.empty())
    {
        curr = bfs_q.front();
        bfs_q.pop_front();
        
        if(curr.row == N - 1 && curr.col == M - 1)
        {
            cout<<visited[curr.row][curr.col] - 1;
            
            break;
        }
        
        if(maze[curr.row][curr.col] == '1')
        {
            visited[curr.row][curr.col]++;
        }
        
        for(i=0; i<4; i++)
        {
            next.row = curr.row + diff_dir[i][0];
            next.col = curr.col + diff_dir[i][1];
            
            if(0 <= next.row && next.row < N &&
               0 <= next.col && next.col < M)
            {
                if(!visited[next.row][next.col])
                {
                    if(maze[next.row][next.col] == '0')
                    {
                        bfs_q.push_front(next);
                    }
                    else
                    {
                        bfs_q.push_back(next);
                    }
                    
                    visited[next.row][next.col] = visited[curr.row][curr.col];
                }
            }
        }
    }
    
    return 0;
}
