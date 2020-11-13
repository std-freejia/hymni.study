/*
1. BFS
2. queue 비어주는 방법 :
   - 순환 pop
   - q = queue<type>();
   - queue<type> empty;
     swap(empty, q);
*/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct pos
{
    int row;
    int col;
};

const int MAX_l = 300;
int l = 0;  // board 크기
queue<pos> bfs_q;
int visited[MAX_l][MAX_l] = {0};  // 방문 체크
int diff[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
                  {1, -2}, {2, -1}, {2, 1}, {1, 2}};  // index 계산

int BFS(pos curr, pos tar);

int main(int argc, char* argv[], char* envs[])
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc_num = 0;  // testcase 개수
    pos curr = {0, 0};  // current position
    pos tar = {0, 0};  // target position
    
    cin>>tc_num;
    
    for(int i=0; i<tc_num; i++)
    {
        // 큐 비워줘야 됨
        queue<pos> empty;
        swap(empty, bfs_q);
        // visited 배열 0으로 초기화
        memset(visited, 0, sizeof(visited));
        
        cin>>l;
        cin>>curr.row>>curr.col;
        cin>>tar.row>>tar.col;
        
        BFS(curr, tar);
    }
    
    return 0;
}

int BFS(pos curr, pos tar)
{
    pos knight = {0, 0};
    pos next = {0, 0};
    
    bfs_q.push(curr);
    visited[curr.row][curr.col] = 1;
    
    while(!bfs_q.empty())
    {
        knight = bfs_q.front();
        bfs_q.pop();
        
        // target 칸 도착하면 출력
        if(knight.row == tar.row && knight.col == tar.col)
        {
            cout<<visited[knight.row][knight.col] - 1<<"\n";
            
            break;
        }
        
        // 8방향 index 체크하고 큐에 push
        for(int i=0; i<8; i++)
        {
            next.row = knight.row + diff[i][0];
            next.col = knight.col + diff[i][1];
            
            // index 밤위 체크
            if(0 <= next.row && next.row < l && 0 <= next.col && next.col < l)
            {
                // 방문된 위치 다시 방문 하지 않는다
                if(!visited[next.row][next.col])
                {
                    bfs_q.push(next);
                    visited[next.row][next.col] = visited[knight.row][knight.col] + 1;
                }
            }
        }
    }
    
    return 0;
}
