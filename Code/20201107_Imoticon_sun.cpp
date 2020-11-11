/*
1. BFS : 노드는 <screen, board> 형태
*/

#include <iostream>
#include <queue>

using namespace std;

struct emo
{
    int screen;
    int board;
};

const int MAX = 1000;
int S = 0;
int visited[MAX + 1][MAX + 1] = {0};  // 방문 체크 & 걸린 시간
queue<emo> bfs_q;

int BFS(emo start);

int main(int argc, char* argv, char* envs[])
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>S;
    
    BFS({1, 0});
    
    return 0;
}

int BFS(emo start)
{
    emo curr = {0, 0};
    emo next = {0, 0};
    
    bfs_q.push(start);
    visited[start.screen][start.board] = 1;
    
    while(!bfs_q.empty())
    {
        curr = bfs_q.front();
        bfs_q.pop();
        
        // 화면에 S개의 이모티콘이 있으면 끝
        if(curr.screen == S)
        {
            cout<<visited[curr.screen][curr.board] - 1;
            
            return 0;
        }
        
        // 복사
        next.screen = curr.screen;
        next.board = curr.screen;
            
        if(!visited[next.screen][next.board])
        {
            visited[next.screen][next.board] = visited[curr.screen][curr.board] + 1;
            bfs_q.push(next);
        }
            
        // 하나를 삭제
        next.screen = curr.screen - 1;
        next.board = curr.board;
            
        if(next.screen >= 0 && !visited[next.screen][next.board])
        {
            visited[next.screen][next.board] = visited[curr.screen][curr.board] + 1;
            bfs_q.push(next);
        }
        
        // 붙여넣기
        next.screen = curr.screen + curr.board;
        next.board = curr.board;
      
        if(next.screen <= MAX && !visited[next.screen][next.board])
        {
            visited[next.screen][next.board] = visited[curr.screen][curr.board] + 1;
            bfs_q.push(next);
        }
    }
    
    return 0;
}
