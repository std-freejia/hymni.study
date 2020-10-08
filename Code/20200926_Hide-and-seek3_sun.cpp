#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

const int MAX_NUM = 100000;
int N = 0;
int K = 0;
int node[MAX_NUM + 1] = {0};
deque<int> q;

int BFS();

int main(int argc, char* argv[], char* envs[])
{
    cin>>N>>K;
    
    memset(node, -1, sizeof(node));
    
    BFS();
    
    return 0;
}

int BFS()
{
    int current = 0;
    
    q.push_back(N);
    node[N] = 0;
    
    while(!q.empty())
    {
        current = q.front();
        q.pop_front();
        
        if(current == K)
        {
            cout<<node[current];
            
            return 0;
        }
        
        if((2 * current) <= MAX_NUM && node[2 * current] == -1)
        {
            q.push_front(2 * current);
            node[2 * current] = node[current];
        }
        
        if(current < MAX_NUM && node[current + 1] == -1)
        {
            q.push_back(current + 1);
            node[current + 1] = node[current] + 1;
        }
        
        if(current > 0 && node[current - 1] == -1)
        {
            q.push_back(current - 1);
            node[current - 1] = node[current] + 1;
        }
    }
    
    return 0;
}
