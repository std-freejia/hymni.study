#include <iostream>
#include <queue>

using namespace std;

struct status
{
    int screen;
    int board;
    int timer;
};

const int MAX = 1000;
int S = 0;
queue<status> bfs_q;
int checked[MAX + 1][MAX + 1] = {0};

int bfs();

int main(int argc, char* argv[], char* envs[])
{
    cin>>S;
    
    bfs_q.push({1, 0, 0});
    checked[1][0] = 1;
    
    bfs();
    
    return 0;
}

int bfs()
{
    while(!bfs_q.empty())
    {
        if(bfs_q.front().screen == S)
        {
            cout<<bfs_q.front().timer;
            
            return 0;
        }
        
        int screen = bfs_q.front().screen;
        int board = bfs_q.front().board;
        int timer = bfs_q.front().timer;
        
        // Copy
        if(checked[screen][screen] == 0)
        {
            bfs_q.push({screen, screen, timer + 1});
            
            checked[screen][screen] = 1;
        }
            
        // Paste
        if(screen + board <= MAX && checked[screen + board][board] == 0)
        {
            bfs_q.push({screen + board, board, timer + 1});
        
            checked[screen + board][board] = 1;
        }
        
        // Delete
        if(screen - 1 >= 0 && checked[screen - 1][board] == 0)
        {
            bfs_q.push({screen - 1, board, timer + 1});
        
            checked[screen - 1][board] = 1;
        }
        
        bfs_q.pop();
    }
    
    return 0;
}
