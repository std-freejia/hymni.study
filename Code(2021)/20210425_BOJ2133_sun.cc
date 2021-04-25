#include <iostream>

using namespace std;

const int MAX_N = 30;
int answer[MAX_N + 1] = {0};
int N = 0;

int main(int argc, char* argv[], char* envs[])
{
    int i = 0;  // used in "for"
    int j = 0;  // used in "for"
    
    cin>>N;
    
    answer[2] = 3;
    
    if(N % 2 == 0)
    {
        for(i=4; i<=N; i+=2)
        {
            answer[i] = answer[i - 2] * 3 + 2;
            
            for(j=2; j<=i-4; j+=2)
            {
                answer[i] += answer[j] * 2;
            }
        }
    }
    
    cout<<answer[N]<<endl;
    
    return 0;
}
