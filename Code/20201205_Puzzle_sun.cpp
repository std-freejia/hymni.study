#include <iostream>
#include <map>
#include <queue>

using namespace std;

const int SIZE = 3;
const string target = "123456780";
int diff_dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
map<string, int> visited;
queue<string> bfs_q;

int BFS(string start);
int boundary_check(int row, int col);

int main(int argc, char* argv, char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i = 0;  // for loop
    int j = 0;  // for loop
    char num = '0';
    string start = "";
    
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            cin>>num;
            
            start += num;
        }
    }
    
    BFS(start);
    
    return 0;
}

int BFS(string start)
{
    int i = 0;  // for loop
    int idx = 0;
    int next_r = 0;
    int next_c = 0;
    string curr = " ";
    string next = " ";
    
    bfs_q.push(start);
    visited[start] = 0;
    
    while(!bfs_q.empty())
    {
        curr = bfs_q.front();
        bfs_q.pop();
        
        if(curr == target)
        {
            cout<<visited[target];
            
            return 0;
        }
        
        idx = curr.find('0');
        
        for(i=0; i<4; i++)
        {
            next_r = idx / SIZE + diff_dir[i][0];
            next_c = idx % SIZE + diff_dir[i][1];
            
            if(boundary_check(next_r, next_c))
            {
                next = curr;
                swap(next[idx], next[next_r * SIZE + next_c]);
                
                if(visited.find(next) == visited.end())
                {
                    bfs_q.push(next);
                    visited[next] = visited[curr] + 1;
                }
            }
        }
    }
    
    cout<<-1;
    
    return 0;
}

int boundary_check(int row, int col)
{
    return (0 <= row && row < SIZE && 0 <= col && col < SIZE);
}
