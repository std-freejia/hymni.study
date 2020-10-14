/*
1. DFS algorithm 사용
2. 네 방향 인접 node의 index를 계산하는 코드를 줄이기 위해 id_diff 배열 사용
3. circle 형성할 수 있는 지를 판단하기 위해 시작 node의 위치를 저장 (s_row, s_col)
*/

#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE = 50;
char board[MAX_SIZE][MAX_SIZE] = {0};  // 게임판
int visited[MAX_SIZE][MAX_SIZE] = {0};  // node 중복 방문 방지
int id_diff[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // 네 방향 index 계산
int N = 0;
int M = 0;
int s_row = 0;  // 시작 node의 행
int s_col = 0;  // 시작 node의 열

int DFS(int row, int col, int counter);

int main(int argc, char* argv[], char* envs[])
{
    // 입력
    cin>>N>>M;
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>board[i][j];
        }
    }
    // 입력 끝
    
    // 모든 node를 순서대로 시작 node로 지정하고 circle 찾기
    for(s_row=0; s_row<N; s_row++)
    {
        for(s_col=0; s_col<M; s_col++)
        {
            DFS(s_row, s_col, 1);
        }
    }
    
    // 중간에 program 종료되지 못하는 경우, circle 없음
    cout<<"No";
    
    return 0;
}

int DFS(int row, int col, int counter)
{
    visited[row][col] = 1;
    
    // 4개 이상 node로 구성하고 마지막 node는 start node랑 인접해야 circle 형성할 수 있음 (2개 node는 circle 아님)
    if(counter >= 4 && 
       (abs(row - s_row) ==1 && col == s_col ||
        abs(col - s_col) ==1 && row == s_row))
    {
        // circle 존재, program 종료시킴
        cout<<"Yes";
        
        exit(0);
    }
    
    // 네 방향 인접 node 모두 확인
    for(int i=0; i<4; i++)
    {
        // 인접 node의 index 계산
        int next_row = row + id_diff[i][0];
        int next_col = col + id_diff[i][1];
        
        // index 범위 체크
        if(0 <= next_row && next_row < N &&
           0 <= next_col && next_col < M)
        {
            // 색갈 체크 & 중복 방문 체크
            if(board[row][col] == board[next_row][next_col] &&
               !visited[next_row][next_col])
            {
                DFS(next_row, next_col, counter + 1);
            }
        }
    }
    
    visited[row][col] = 0;
    
    return 0;
}
