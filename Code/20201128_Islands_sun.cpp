#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct pos
{
    int row;
    int col;
};

const int MAX = 50;
int w = 0;
int h = 0;
int map[MAX][MAX] = {0};
int visited[MAX][MAX] = {0};
int diff_dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                      {1, -1}, {1, 0}, {1, 1},
                      {0, -1}, {0, 1}};
int counter = 0;
queue<pos> bfs_q;

int BFS(pos start);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i = 0;  // for loop
    int j = 0;  // for loop
    
    while(1)
    {
        cin>>w>>h;
        
        memset(visited, 0, sizeof(visited));
        counter = 0;
        
        if(w == 0 || h == 0)
        {
            break;
        }
        
        for(i=0; i<h; i++)
        {
            for(j=0; j<w; j++)
            {
                cin>>map[i][j];
            }
        }
        
        for(i=0; i<h; i++)
        {
            for(j=0; j<w; j++)
            {
                if(map[i][j] && !visited[i][j])
                {
                    BFS({i, j});
                    
                    counter++;
                }
            }
        }
        
        cout<<counter<<"\n";
    }
    
    return 0;
}

int BFS(pos start)
{
    int i = 0;
    pos curr = {0, 0};
    pos next = {0, 0};
    
    bfs_q.push(start);
    visited[start.row][start.col] = 1;
    
    while(!bfs_q.empty())
    {
        curr = bfs_q.front();
        bfs_q.pop();
        
        for(i=0; i<8; i++)
        {
            next.row = curr.row + diff_dir[i][0];
            next.col = curr.col + diff_dir[i][1];
            
            if(0 <= next.row && next.row < h &&
               0 <= next.col && next.col < w)
            {
                if(map[next.row][next.col] && !visited[next.row][next.col])
                {
                    bfs_q.push(next);
                    visited[next.row][next.col] = 1;
                }
            }
        }
    }
    
    return 0;
}
