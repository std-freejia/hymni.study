#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct pos
{
    int row;
    int col;
};

const int MAX = 100;
int h = 0;
int w = 0;
int visited[MAX][MAX] = {0};
int diff_dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
string key = "";
vector<string> map;
vector<pos> door;
queue<pos> bfs_q;

int find_entrance();
int BFS();
int boundary_check(int row, int col);
int operate(int row, int col);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i = 0;  // for loop
    int T = 0;
    string s = "";
    
    cin>>T;
    
    while(T--)
    {
        cin>>h>>w;
        
        map.clear();
        door.clear();
        key.clear();
        memset(visited, 0, sizeof(visited));
        
        for(i=0; i<h; i++)
        {
            cin>>s;
            
            map.push_back(s);
        }
        
        cin>>key;
        
        find_entrance();
        
        BFS();
    }
    
    return 0;
}

int find_entrance()
{
    int row = 0;  // for loop
    int col = 0;  // for loop
    
    for(row=0; row<h; row++)
    {
        for(col=0; col<w; col++)
        {
            if(0 < row && row < h - 1 && 0 < col && col < w - 1)
            {
                continue;
            }
            
            operate(row, col);
        }
    }
    
    return 0;
}

int BFS()
{
    int i = 0;  // for loop
    int file = 0;
    pos curr = {0, 0};
    pos next = {0, 0};
    
    while(!bfs_q.empty())
    {
        curr = bfs_q.front();
        bfs_q.pop();
        
        if(map[curr.row][curr.col] == '$')
        {
            file++;
        }
        
        for(i=0; i<4; i++)
        {
            next.row = curr.row + diff_dir[i][0];
            next.col = curr.col + diff_dir[i][1];
            
            if(boundary_check(next.row, next.col))
            {
                if(!visited[next.row][next.col])
                {
                    operate(next.row, next.col);
                }
            }
        }
    }
    
    cout<<file<<"\n";
    
    return 0;
}

int boundary_check(int row, int col)
{
    return (0 <= row && row < h && 0 <= col && col < w);
}

int operate(int row, int col)
{
    // cannot enter
    if(map[row][col] == '*')
    {
        return 0;
    }
    
    // door
    if('A' <= map[row][col] && map[row][col] <= 'Z')
    {
        if(key.find(map[row][col] + 32) == key.npos)
        {
            door.push_back({row, col});
            
            return 0;
        }
        
        bfs_q.push({row, col});
        visited[row][col] = 1;
        
        return 0;
    }
    
    // found entrance
    if('a' <= map[row][col] && map[row][col] <= 'z')
    {
        if(key.find(map[row][col]) == key.npos)
        {
            key += map[row][col];
            
            for(int i=0; i<door.size(); i++)
            {
                if(map[door[i].row][door[i].col] + 32 == map[row][col])
                {
                    bfs_q.push({door[i].row, door[i].col});
                    visited[door[i].row][door[i].col] = 1;
                    door.erase(door.begin() + i);
                    i--;
                }
            }
        }
    }
    
    bfs_q.push({row, col});
    visited[row][col] = 1;
    
    return 0;
}
