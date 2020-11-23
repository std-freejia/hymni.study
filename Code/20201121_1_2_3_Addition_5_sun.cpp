#include <iostream>

using namespace std;

const int MAX = 100000;
unsigned int solution[MAX + 1][4] = {0};

int main(int argc, char* argv, char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T = 0;
    int n = 0;
    int i = 0;
    
    solution[1][1] = 1;
    solution[2][2] = 1;
    solution[3][1] = 1;
    solution[3][2] = 1;
    solution[3][3] = 1;
    
    for(i=4; i<=MAX; i++)
    {
        solution[i][1] = (solution[i - 1][2] + solution[i - 1][3]) % 1000000009;
        solution[i][2] = (solution[i - 2][1] + solution[i - 2][3]) % 1000000009;
        solution[i][3] = (solution[i - 3][1] + solution[i - 3][2]) % 1000000009;
    }
    
    cin>>T;
    
    for(i=0; i<T; i++)
    {
        cin>>n;
        cout<<(solution[n][1] + solution[n][2] + solution[n][3]) % 1000000009<<"\n";
    }
    
    return 0;
}
