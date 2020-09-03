#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_size = 500;
int N = 0;
int M = 0;
int map[MAX_size][MAX_size] = {0};
int max_sum = 0;

int calculate(int row, int col);

int main(int argc, char* argv[], char* envs[])
{
    int row = 0;
    int col = 0;
    
    cin>>N>>M;
    
    for(row=0; row<N; row++)
    {
        for(col=0; col<M; col++)
        {
            cin>>map[row][col];
        }
    }
    
    for(row=0; row<N; row++)
    {
        for(col=0; col<M; col++)
        {
            calculate(row, col);
        }
    }
    
    cout<<max_sum<<endl;
    
    return 0;
}

int calculate(int row, int col)
{
    int current_sum = 0;
    
    // blue 4*1
    if((row + 3) < N)
    {
        current_sum = map[row][col] + map[row + 1][col] + map[row + 2][col] + map[row + 3][col];
        max_sum = max(max_sum, current_sum);
    }
    
    // blue 1*4
    if((col + 3) < M)
    {
        current_sum = map[row][col] + map[row][col + 1] + map[row][col + 2] + map[row][col + 3];
        max_sum = max(max_sum, current_sum);
    }
    
    // yellow 2*2
    if((row + 1) < N && (col + 1) < M)
    {
        current_sum = map[row][col] + map[row + 1][col] + map[row][col + 1] + map[row + 1][col + 1];
        max_sum = max(max_sum, current_sum);
    }
    
    // 3*2
    if((row + 2) < N && (col + 1) < M)
    {
        // orange
        current_sum = map[row][col] + map[row + 1][col] + map[row + 2][col] + map[row + 2][col + 1];
        max_sum = max(max_sum, current_sum);
        
        current_sum = map[row][col] + map[row + 1][col] + map[row + 2][col] + map[row][col + 1];
        max_sum = max(max_sum, current_sum);
        
        current_sum = map[row][col + 1] + map[row + 1][col + 1] + map[row + 2][col + 1] + map[row + 2][col];
        max_sum = max(max_sum, current_sum);
        
        current_sum = map[row][col + 1] + map[row + 1][col + 1] + map[row + 2][col + 1] + map[row][col];
        max_sum = max(max_sum, current_sum);
        
        // green
        current_sum = map[row][col] + map[row + 1][col] + map[row + 1][col + 1] + map[row + 2][col + 1];
        max_sum = max(max_sum, current_sum);
        
        current_sum = map[row][col + 1] + map[row + 1][col] + map[row + 1][col + 1] + map[row + 2][col];
        max_sum = max(max_sum, current_sum);
        
        // pink
        current_sum = map[row][col] + map[row + 1][col] + map[row + 1][col + 1] + map[row + 2][col];
        max_sum = max(max_sum, current_sum);
        
        current_sum = map[row][col + 1] + map[row + 1][col] + map[row + 1][col + 1] + map[row + 2][col + 1];
        max_sum = max(max_sum, current_sum);    
    }
    
    // 2*3
    if((row + 1) < N && (col + 2) < M)
    {
        // orange
        current_sum = map[row][col] + map[row + 1][col] + map[row + 1][col + 1] + map[row + 1][col + 2];
        max_sum = max(max_sum, current_sum);
        
        current_sum = map[row][col + 2] + map[row + 1][col] + map[row + 1][col + 1] + map[row + 1][col + 2];
        max_sum = max(max_sum, current_sum);
        
        current_sum = map[row][col] + map[row][col + 1] + map[row][col + 2] + map[row + 1][col];
        max_sum = max(max_sum, current_sum);
        
        current_sum = map[row][col] + map[row][col + 1] + map[row][col + 2] + map[row + 1][col + 2];
        max_sum = max(max_sum, current_sum);
        
        // green
        current_sum = map[row][col] + map[row][col + 1] + map[row + 1][col + 1] + map[row + 1][col + 2];
        max_sum = max(max_sum, current_sum);
        
        current_sum = map[row][col + 1] + map[row][col + 2] + map[row + 1][col] + map[row + 1][col + 1];
        max_sum = max(max_sum, current_sum);
        
        // pink
        current_sum = map[row][col] + map[row][col + 1] + map[row][col + 2] + map[row + 1][col + 1];
        max_sum = max(max_sum, current_sum);
        
        current_sum = map[row][col + 1] + map[row + 1][col] + map[row + 1][col + 1] + map[row + 1][col + 2];
        max_sum = max(max_sum, current_sum);    
    }
    
    return 0;
}
