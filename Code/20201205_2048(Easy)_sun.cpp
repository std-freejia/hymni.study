#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N  = 20;
const int MAX_counter = 5;
int N = 0;
int max_num = 0;
int board[MAX_N][MAX_N] = {0};

int game_2048(int board[MAX_N][MAX_N], int counter);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i = 0;  // for loop
    int j = 0;  // for loop
    
    cin>>N;
    
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            cin>>board[i][j];
            
            max_num = max(max_num, board[i][j]);
        }
    }
    
    game_2048(board, 0);
    
    cout<<max_num;
    
    return 0;
}

int game_2048(int board[MAX_N][MAX_N], int counter)
{
    int row = 0;
    int col = 0;
    int idx_p = 0;
    int new_board[MAX_N][MAX_N] = {0};
    
    if(counter >= 5)
    {
        for(row=0; row<N; row++)
        {
            for(col=0; col<N; col++)
            {
                max_num = max(max_num, board[row][col]);
            }
        }
        
        return 0;
    }
    
    // 위
    memset(new_board, 0, sizeof(new_board));
    for(col=0; col<N; col++)
    {
        idx_p = 0;
        
        for(row=0; row<N; row++)
        {
            if(board[row][col] == 0)
            {
                continue;
            }
            
            if(new_board[idx_p][col] == 0)
            {
                new_board[idx_p][col] = board[row][col];
            }
            else if(new_board[idx_p][col] == board[row][col])
            {
                new_board[idx_p][col] += board[row][col];
                max_num = max(max_num, new_board[idx_p][col]);
                idx_p++;
            }
            else
            {
                idx_p++;
                new_board[idx_p][col] = board[row][col];
            }
        }
    }
    game_2048(new_board, counter + 1);
    
    // 아래
    memset(new_board, 0, sizeof(new_board));
    for(col=0; col<N; col++)
    {
        idx_p = N - 1;
        
        for(row=N-1; row>=0; row--)
        {
            if(board[row][col] == 0)
            {
                continue;
            }
            
            if(new_board[idx_p][col] == 0)
            {
                new_board[idx_p][col] = board[row][col];
            }
            else if(new_board[idx_p][col] == board[row][col])
            {
                new_board[idx_p][col] += board[row][col];
                max_num = max(max_num, new_board[idx_p][col]);
                idx_p--;
            }
            else
            {
                idx_p--;
                new_board[idx_p][col] = board[row][col];
            }
        }
    }
    game_2048(new_board, counter + 1);
    
    // 왼쪽
    memset(new_board, 0, sizeof(new_board));
    for(row=0; row<N; row++)
    {
        idx_p = 0;
        
        for(col=0; col<N; col++)
        {
            if(board[row][col] == 0)
            {
                continue;
            }
            
            if(new_board[row][idx_p] == 0)
            {
                new_board[row][idx_p] = board[row][col];
            }
            else if(new_board[row][idx_p] == board[row][col])
            {
                new_board[row][idx_p] += board[row][col];
                max_num = max(max_num, new_board[row][idx_p]);
                idx_p++;
            }
            else
            {
                idx_p++;
                new_board[row][idx_p] = board[row][col];
            }
        }
    }
    game_2048(new_board, counter + 1);
    
    // 오른쪽
    memset(new_board, 0, sizeof(new_board));
    for(row=0; row<N; row++)
    {
        idx_p = N - 1;
        
        for(col=N-1; col>=0; col--)
        {
            if(board[row][col] == 0)
            {
                continue;
            }
            
            if(new_board[row][idx_p] == 0)
            {
                new_board[row][idx_p] = board[row][col];
            }
            else if(new_board[row][idx_p] == board[row][col])
            {
                new_board[row][idx_p] += board[row][col];
                max_num = max(max_num, new_board[row][idx_p]);
                idx_p--;
            }
            else
            {
                idx_p--;
                new_board[row][idx_p] = board[row][col];
            }
        }
    }
    game_2048(new_board, counter + 1);
    
    return 0;
}
