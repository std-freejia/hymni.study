#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int max_len = 1;

int line_up(int* line, int* len, int N);

int main(int argc, char* argv[], char* envs[])
{
    int N;
    
    cin>>N;
    
    if(N < 2 || N > 200)
    {
        exit(1);
    }
    
    int line[N] = {0};
    int len[N] = {0};
    
    for(int i=0; i<N; i++)
    {
        cin>>line[i];
        
        if(line[i] < 1 || line[i] > 200)
        {
            exit(1);
        }
        
        len[i] = 1;
    }
    
    line_up(line, len, N);
    
    cout<<(N - max_len);
    
    return 0;
}

int line_up(int* line, int* len, int N)
{
    for(int last_id=1; last_id<N; last_id++)
    {
        for(int front=0; front<last_id; front++)
        {
            if(line[front] < line[last_id])
            {
                len[last_id] = max(len[last_id], len[front]+1);
            }
        }
    }

    sort(len, len+N);
    
    max_len = len[N-1];
    
    return 0;
}
