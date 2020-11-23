/*
1. DP
3. 2*n = 2*(n-1) 뒤에 2*1 타일 추가 + 2*(n-2) 뒤에 1*2 타일 추가
2. n = 1 : 2*1
   n = 2 : 2*1+2*1, 1*2+1*2
   n = 3 : (2*1+2*1)+2*1, (1*2+1*2)+2*1, (2*1)+1*2
   ......
*/

#include <iostream>

using namespace std;

const int MAX = 1000;
int solution[MAX + 1] = {0};

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n = 0;
    
    cin>>n;
    
    solution[1] = 1;
    solution[2] = 2;
    
    for(int i=3; i<=n; i++)
    {
        solution[i] = (solution[i - 1] + solution[i - 2]) % 10007;
    }
    
    cout<<solution[n];
    
    return 0;
}
