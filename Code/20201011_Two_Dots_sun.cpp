#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE = 50;
char board[MAX_SIZE][MAX_SIZE] = {0};
int visited[MAX_SIZE][MAX_SIZE] = {0};
int id_diff[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int N = 0;
int M = 0;
int s_row = 0;
int s_col = 0;

int DFS(int row, int col, int counter);

int main(int argc, char* argv[], char* envs[])
{
    cin>>N>>M;
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>board[i][j];
        }
    }
    
    for(s_row=0; s_row<N; s_row++)
    {
        for(s_col=0; s_col<M; s_col++)
        {
            DFS(s_row, s_col, 1);
        }
    }
    
    cout<<"No";
    
    return 0;
}

int DFS(int row, int col, int counter)
{
    visited[row][col] = 1;
    
    if(counter >= 4 && 
       (abs(row - s_row) ==1 && col == s_col ||
        abs(col - s_col) ==1 && row == s_row))
    {
        cout<<"Yes";
        
        exit(0);
    }
    
    for(int i=0; i<4; i++)
    {
        int next_row = row + id_diff[i][0];
        int next_col = col + id_diff[i][1];
        
        if(0 <= next_row && next_row < N &&
           0 <= next_col && next_col < M)
        {
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
