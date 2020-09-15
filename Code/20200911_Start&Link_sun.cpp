#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 20;
int N = 0;
int S[MAX_N][MAX_N] = {0};
int choose[MAX_N] = {0};
int min_diff = 1000;

int grouping(int counter, int index);
int diff_cal();

int main(int argc, char* argv[], char* envs[])
{
    cin>>N;
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>S[i][j];
        }
    }
    
    int counter = 0;
    int index = 0;
    
    grouping(counter, index);
    
    cout<<min_diff<<endl;
    
    return 0;
}

int grouping(int counter, int index)
{
    if(counter == (N / 2))
    {
        min_diff = min(min_diff, diff_cal());
        
        return 0;
    }
    
    for(int i=index; i<N; i++)
    {
        choose[i] = 1;
        
        grouping(counter + 1, i + 1);
        
        choose[i] = 0;
    }
    
    return 0;
}

int diff_cal()
{
    vector<int> start;
    vector<int> link;
    int start_value = 0;
    int link_value = 0;
        
    for(int i=0; i<N; i++)
    {
        if(choose[i] == 1)
        {
            start.push_back(i);
        }
        else
        {
            link.push_back(i);
        }
    }
    
    while(!start.empty())
    {
        for(int i=start.size()-2; i>=0; i--)
        {
            start_value += S[start[i]][start.back()];
            start_value += S[start.back()][start[i]];
            
            link_value += S[link[i]][link.back()];
            link_value += S[link.back()][link[i]];
        }
        
        start.pop_back();
        link.pop_back();
    }
    
    return abs(start_value - link_value);
}
