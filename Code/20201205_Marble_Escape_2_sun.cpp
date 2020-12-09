#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct status
{
    int row_R;
    int col_R;
    int row_B;
    int col_B;
};

const int MAX = 10;
int N = 0;
int M = 0;
int visited[MAX][MAX][MAX][MAX] = {0};
int diff_dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
status start = {0, 0, 0, 0};
status stop = {0, 0, 0, 0};
vector<string> map;
queue<status> bfs_q;

int BFS();

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i = 0;  // for loop
    int j = 0;  // for loop
    string s = " ";
    
    cin>>N>>M;
    
    for(i=0; i<N; i++)
    {
        cin>>s;
        
        map.push_back(s);
        
        for(j=0; j<M; j++)
        {
            if(map[i][j] == 'R')
            {
                start.row_R = i;
                start.col_R = j;
            }
            
            if(map[i][j] == 'B')
            {
                start.row_B = i;
                start.col_B = j;
            }
            
            if(map[i][j] == 'O')
            {
                stop.row_R = i;
                stop.col_R = j;
            }
        }
    }
    
    BFS();
    
    return 0;
}

int BFS()
{
    int i = 0;  // for loop
    int counter = 0;
    status curr = {0, 0, 0, 0};
    status next = {0, 0, 0, 0};
    
    bfs_q.push(start);
    visited[start.row_R][start.col_R][start.row_B][start.col_B] = 1;
    
    while(!bfs_q.empty())
    {
        curr = bfs_q.front();
        next = bfs_q.front();
        bfs_q.pop();
        
        if(visited[curr.row_R][curr.col_R][curr.row_B][curr.col_B] > MAX + 1)
        {
            break;
        }
        
        if(curr.row_R == stop.row_R && curr.col_R == stop.col_R)
        {
            cout<<visited[curr.row_R][curr.col_R][curr.row_B][curr.col_B] - 1;
            
            return 0;
        }
        
        for(i=0; i<4; i++)
        {
            next = curr;
            
            while(1)
            {
                next.row_R += diff_dir[i][0];
                next.col_R += diff_dir[i][1];
                
                if(map[next.row_R][next.col_R] == '#')
                {
                    next.row_R -= diff_dir[i][0];
                    next.col_R -= diff_dir[i][1];
                    break;
                }
                
                if(map[next.row_R][next.col_R] == 'O')
                {
                    break;
                }
            }
            
            while(1)
            {
                next.row_B += diff_dir[i][0];
                next.col_B += diff_dir[i][1];
                
                if(map[next.row_B][next.col_B] == '#')
                {
                    next.row_B -= diff_dir[i][0];
                    next.col_B -= diff_dir[i][1];
                    break;
                }
                
                if(map[next.row_B][next.col_B] == 'O')
                {
                    break;
                }
            }
            
            if(map[next.row_B][next.col_B] == 'O')
            {
                continue;
            }
            
            if(next.row_R == next.row_B && next.col_R == next.col_B)
            {
                switch(i)
                {
                    case 0:
                        {
                            if(curr.row_R > curr.row_B)
                            {
                                next.row_R++;
                            }
                            else
                            {
                                next.row_B++;
                            }
                            
                            break;
                        }
                    case 1:
                        {
                            if(curr.row_R < curr.row_B)
                            {
                                next.row_R--;
                            }
                            else
                            {
                                next.row_B--;
                            }
                            
                            break;
                        }
                    case 2:
                        {
                            if(curr.col_R > curr.col_B)
                            {
                                next.col_R++;
                            }
                            else
                            {
                                next.col_B++;
                            }
                            
                            break;
                        }
                    case 3:
                        {
                            if(curr.col_R < curr.col_B)
                            {
                                next.col_R--;
                            }
                            else
                            {
                                next.col_B--;
                            }
                        }
                }
            }
            
            if(!visited[next.row_R][next.col_R][next.row_B][next.col_B])
            {
                visited[next.row_R][next.col_R][next.row_B][next.col_B] = visited[curr.row_R][curr.col_R][curr.row_B][curr.col_B] + 1;
                bfs_q.push(next);
            }
        }
    }
    
    cout<<-1;
    
    return 0;
}
