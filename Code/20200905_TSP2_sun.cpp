#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 10;
int N = 0;
int W[MAX_N][MAX_N] = {0};
int checked[MAX_N] = {0};
int min_cost = 10000000;
int start = 0;

int TSP(int current, int counter, int cost);

int main(int argc, char* argv[], char* envs[])
{
    cin>>N;
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>W[i][j];
        }
    }
    
    int counter = 0;
    int cost = 0;
    int current = 0;
    
    for(start=0; start<N; start++)
    {
        current = start;
        counter = 1;
        cost = 0;
        
        checked[start] = 1;
        
        TSP(current, counter, cost);
        
        checked[start] = 0;
    }
    
    cout<<min_cost<<endl;
    
    return 0;
}

int TSP(int current, int counter, int cost)
{
    if(counter == N)
    {
        if(W[current][start] > 0)
        {
            min_cost = min(min_cost, cost += W[current][start]);
        }
        
        return 0;
    }
    
    for(int i=0; i<N; i++)
    {
        if(checked[i] == 0 && W[current][i] > 0)
        {
            checked[i] = 1;
            
            TSP(i, counter + 1, cost + W[current][i]);
            
            checked[i] = 0;
        }
    }
    
    return 0;
}
