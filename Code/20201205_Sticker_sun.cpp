#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int T = 0;
int score[2][MAX + 1] = {0};
int sum[2][MAX + 1] = {0};

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n = 0;
    int i = 0;  // for loop
    int j = 0;  // for loop
    
    cin>>T;
    
    while(T--)
    {
        cin>>n;
        
        for(i=0; i<2; i++)
        {
            for(j=1; j<=n; j++)
            {
                cin>>score[i][j];
            }
        }
        
        sum[0][1] = score[0][1];
        sum[1][1] = score[1][1];
        
        for(i=2; i<=n; i++)
        {
            sum[0][i] = max(sum[1][i - 2], sum[1][i - 1]) + score[0][i];
            sum[1][i] = max(sum[0][i - 2], sum[0][i - 1]) + score[1][i];
        }
        
        cout<<max(sum[0][n], sum[1][n])<<"\n";
    }
    
    return 0;
}
