#include <iostream>

using namespace std;

const int MAX_N = 100;
int N = 0;
int counter[MAX_N + 1][10] = {0};

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i = 0;  // for loop
    int j = 0;  // for loop
    int sum = 0;
    
    cin>>N;
    
    counter[1][0] = 0;
    for(i=1; i<10; i++)
    {
        counter[1][i] = 1;
    }
    
    for(i=2; i<=N; i++)
    {
        counter[i][0] = counter[i - 1][1];
        counter[i][9] = counter[i - 1][8];
        
        for(j=1; j<9; j++)
        {
            counter[i][j] = (counter[i - 1][j - 1] + counter[i - 1][j + 1]) % 1000000000;
        }
    }
    
    for(i=0; i<10; i++)
    {
        sum += counter[N][i];
        sum %= 1000000000;
    }
    
    cout<<sum;
    
    return 0;
}
