/*
1. DP
2. N = 1 의 경우 : 0, 0
                  1, 0
                  0, 1
3. solve(n) = n(0,0) + n((0,1) or (1,0));
4. n(0,0) = n-1(0,0) + n-1((0,1) or (1,0));
   n((0,1) or (1,0)) = 2*(n-1(0,0)) + n-1((0,1) or (1,0));
*/

#include <iostream>

using namespace std;

const int MAX = 100000;
int solution[MAX + 1][2] = {0};  // solution[i][0] : n(0,0)
                                 // solution[i][1] : n((0,1) or (1,0))

int main(int argc, char* argv[], char* envs[])
{
    int N = 0;
    
    cin>>N;
    
    // N = 1 의 경우 : n(0,0) = 1
    //                n((0,1) or (1,0)) = 2
    solution[1][0] = 1;
    solution[1][1] = 2;
    
    for(int i=2; i<=N; i++)
    {
        solution[i][0] = (solution[i-1][0] + solution[i-1][1]) % 9901;
        solution[i][1] = (solution[i-1][0] * 2 + solution[i-1][1]) % 9901;
    }

    cout<<(solution[N][0] + solution[N][1]) % 9901;
    
    return 0;
}
