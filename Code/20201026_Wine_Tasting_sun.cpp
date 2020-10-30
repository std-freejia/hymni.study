#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10000;
int wine[MAX + 1] = {0};
int result[MAX + 1] = {0};
int n = 0;

int main(int argc, char* argv[], char* envs[])
{
    cin>>n;
    
    for(int i=1; i<=n; i++)
    {
        cin>>wine[i];
    }
    
    result[1] = wine[1];
    result[2] = wine[1] + wine[2];
    
    for(int i=3; i<=n; i++)
    {
        result[i] = max(result[i-3] + wine[i-1] + wine[i], result[i-2] + wine[i]);
        result[i] = max(result[i], result[i-1]);
    }
    
    cout<<result[n];
    
    return 0;
}
