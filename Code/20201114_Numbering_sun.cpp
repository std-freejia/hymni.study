/*
1. BFS
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// position
struct pos
{
    int row;
    int col;
};

const int MAX_SIZE = 25;
int N = 0;
string map[MAX_SIZE] = {" "};
int dir_diff[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // index 계산
int visited[MAX_SIZE][MAX_SIZE] = {0};  // 방문 체크
vector<int> houses;  // 각 단지 집의 수
queue<pos> bfs_q;

int BFS(pos start);

int main(int argc, char* argv[], char* envs[])
{
    int i = 0;  // for loop
    int j = 0;  // for loop
    
    cin>>N;
    
    for(i=0; i<N; i++)
    {
        cin>>map[i];
    }
    
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            // 미방문한 집이 있는 곳부터 탐색
            if(map[i][j] == '1' && !visited[i][j])
            {
                BFS({i, j});
            }
        }
    }
    
    // 단지내 집의 수를 오름차순으로 정렬
    sort(houses.begin(), houses.end());
    
    // 총 단지수 출력
    cout<<houses.size()<<"\n";
    
    // 각 단지내 집의 수 출력
    for(i=0; i<houses.size(); i++)
    {
        cout<<houses[i]<<"\n";
    }
    
    return 0;
}

int BFS(pos start)
{
    int counter = 0;  // 단지내 집의 수 counting
    pos curr = {0, 0};
    pos adj = {0, 0};
        
    queue<pos> empty;
    bfs_q = empty;
    
    bfs_q.push(start);
    visited[start.row][start.col] = 1;
    counter++;
    
    while(!bfs_q.empty())
    {
        curr = bfs_q.front();
        bfs_q.pop();
        
        for(int i=0; i<4; i++)
        {
            adj.row = curr.row + dir_diff[i][0];
            adj.col = curr.col + dir_diff[i][1];
            
            // index 범위 체크
            if(0 <= adj.row && adj.row < N && 0 <= adj.col && adj.col < N)
            {
                // 미방문 인접 집이 있으면 큐에 push
                if(!visited[adj.row][adj.col] && map[adj.row][adj.col] == '1')
                {
                    bfs_q.push(adj);
                    visited[adj.row][adj.col] = 1;
                    counter++;
                }
            }
        }
    }
    
    // 단지내 집의 수 저장
    houses.push_back(counter);
    
    return 0;
}
