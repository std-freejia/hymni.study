#include <iostream>

using namespace std;

int N = 0;
int chessboard[14][14] = {0};
int solution_num = 0;

int fill_chessboard(int row, int col, int value);
int N_Queen(int queen_id);

int main(int argc, char* argv[], char* envs[])
{
    cin>>N;
    
    if(N < 1 || N >= 15)
    {
        cout<<"Bad input!"<<endl;
        exit(-1);
    }

    /* Place queens */
    int queen_id = 0;
    
    N_Queen(queen_id);
    
    cout<<solution_num<<endl;
    
    return 0;
}

int fill_chessboard(int row, int col, int value)
{
    int current_row = 0;
    int current_col = 0;
    
    // Fill same col
    for(current_row; current_row<N; current_row++)
    {
        chessboard[current_row][col] += value;
    }
    
    // Fill left infeasible place
    int row_upper = row - 1;
    int row_lower = row + 1;
    
    for(current_col=col-1; current_col>=0; current_col--)
    {
        // Same row
        chessboard[row][current_col] += value;
        
        // Upper left
        if(row_upper >= 0)
        {
            chessboard[row_upper--][current_col] += value;
        }
        
        // Lower left
        if(row_lower < N)
        {
            chessboard[row_lower++][current_col] += value;
        }
    }
    
    // Fill right infeasible place
    row_upper = row - 1;
    row_lower = row + 1;

    for(current_col=col+1; current_col<N; current_col++)
    {
        // Same row
        chessboard[row][current_col] += value;
        
        // Upper right
        if(row_upper >= 0)
        {
            chessboard[row_upper--][current_col] += value;
        }
        
        // Lower right
        if(row_lower < N)
        {
            chessboard[row_lower++][current_col] += value;
        }
    }
    
    return 0;
}

int N_Queen(int queen_id)
{
    int row = queen_id;
    int col = 0;

    if(queen_id >= N)
    {
        solution_num++;
    }
    else
    {
        /* Place the ith queen in the ith row */
        for(col=0; col<N; col++)
        {
	        if(chessboard[row][col] == 0)
            {
	            fill_chessboard(row, col, 1);

	            N_Queen(queen_id + 1);

                fill_chessboard(row, col, -1);
            }
        }
    }
    
    return 0;
}
