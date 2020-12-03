#include <iostream>
#include <queue>

using namespace std;

struct cell
{
    int row;
    int col;
};

const int MAX = 1000;
int M = 0;
int N = 0;
int raw = 0;
int diff_dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int box[MAX][MAX] = {0};
int timer[MAX][MAX] = {0};
queue<cell> bfs_q;

int BFS();

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i = 0;  // for loop
    int j = 0;  // for loop
    
    cin>>M>>N;
    
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            cin>>box[i][j];
            
            if(box[i][j] == 0)
            {
                raw++;
            }
            
            if(box[i][j] == 1)
            {
                bfs_q.push({i, j});
            }
        }
    }
    
    BFS();
    
    return 0;
}

int BFS()
{
    int i = 0;  // for loop
    int result = 0;
    cell curr = {0, 0};
    cell next = {0, 0};
    
    while(!bfs_q.empty())
    {
        curr = bfs_q.front();
        bfs_q.pop();
        
        result = timer[curr.row][curr.col];
        
        for(i=0; i<4; i++)
        {
            next.row = curr.row + diff_dir[i][0];
            next.col = curr.col + diff_dir[i][1];
            
            if(0 <= next.row && next.row < N &&
               0 <= next.col && next.col < M)
            {
                if(!box[next.row][next.col])
                {
                    box[next.row][next.col] = 1;
                    timer[next.row][next.col] = timer[curr.row][curr.col] + 1;
                    bfs_q.push(next);
                    raw--;
                }
            }
        }
    }
    
    if(raw > 0)
    {
        cout<<-1;
    }
    else
    {
        cout<<result;
    }
    
    return 0;
}
