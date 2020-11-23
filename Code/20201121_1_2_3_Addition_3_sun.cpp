#include <iostream>

using namespace std;

const int MAX = 1000000;
unsigned int solution[MAX + 1] = {0};

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T = 0;
    int n = 0;
    int i = 0;  // for loop
    
    cin>>T;
    
    solution[1] = 1;
    solution[2] = 2;
    solution[3] = 4;
    
    for(i=4; i<=MAX; i++)
    {
        solution[i] = (solution[i - 1] + solution[i - 2] + solution[i - 3]) % 1000000009;
    }
    
    for(i=0; i<T; i++)
    {
        cin>>n;
        cout<<solution[n]<<"\n";
    }
    
    return 0;
}
