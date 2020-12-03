#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct pos
{
    int row;
    int col;
    char status;
};

const int MAX = 50;
int R = 0;
int C = 0;
int visited[MAX][MAX] = {0};
int diff_dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
pos D = {0, 0, '.'};
pos S = {0, 0, '.'};
vector<string> map;
queue<pos> bfs_q;

int BFS();

int main(int argc, char* aragv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i = 0;  // for loop
    int j = 0;  // for loop
    string s = " ";
    
    cin>>R>>C;
    
    for(i=0; i<R; i++)
    {
        cin>>s;
        
        map.push_back(s);
        
        for(j=0; j<C; j++)
        {
            if(s[j] == 'D')
            {
                D.row = i;
                D.col = j;
            }
            
            if(s[j] == 'S')
            {
                S.row = i;
                S.col = j;
                map[i][j] = '.';
            }
            
            if(s[j] == '*')
            {
                bfs_q.push({i, j, '*'});
            }
        }
    }
    
    BFS();
    
    return 0;
}

int BFS()
{
    int i = 0;  // for loop
    pos curr = {0, 0, ' '};
    pos next = {0, 0, ' '};
    
    bfs_q.push(S);
    visited[S.row][S.col] = 1;
    
    while(!bfs_q.empty())
    {
        curr = bfs_q.front();
        bfs_q.pop();
        
        if(curr.row == D.row && curr.col == D.col)
        {
            cout<<visited[D.row][D.col] - 1;
            
            return 0;
        }
        
        for(i=0; i<4; i++)
        {
            next.row = curr.row + diff_dir[i][0];
            next.col = curr.col + diff_dir[i][1];
            
            if(0 <= next.row && next.row < R &&
               0 <= next.col && next.col < C)
            {
                if(curr.status == '*')
                {
                    if(map[next.row][next.col] == '.')
                    {
                        next.status = '*';
                        bfs_q.push(next);
                        map[next.row][next.col] = '*';
                    }
                }
                
                if(curr.status == '.')
                {
                    if(map[next.row][next.col] == 'D' || (map[next.row][next.col] == '.' && !visited[next.row][next.col]))
                    {
                        next.status = '.';
                        bfs_q.push(next);
                        visited[next.row][next.col] = visited[curr.row][curr.col] + 1;
                    }
                }
            }
        } 
    }
    
    cout<<"KAKTUS";
    
    return 0;
}
