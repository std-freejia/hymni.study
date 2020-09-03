#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAX_N = 8;
int N = 0;
int answer = 0;
int accessed[MAX_N] = {0};
vector<int> original_arr;
vector<int> target_arr;

int max_diff(int index);

int main(int argc, char* argv[], char* envs[])
{
    cin>>N;
    
    int num = 0;
    int index = 0;
    
    for(int i=0; i<N; i++)
    {
        cin>>num;
        
        original_arr.push_back(num);
    }
    
    max_diff(index);
    
    cout<<answer<<endl;
    
    return 0;
}

int max_diff(int index)
{
    if(index == N)
    {
        int sum = 0;
        
        for(int i=0; i<N-1; i++)
        {
            sum += abs(target_arr[i] - target_arr[i+1]);
        }
        
        if(sum > answer)
        {
            answer = sum;
        }
        
        return 0;
    }
    
    for(int i=0; i<N; i++)
    {
        if(accessed[i] == 0)
        {
            target_arr.push_back(original_arr[i]);
            
            accessed[i] = 1;
            
            max_diff(index + 1);
            
            target_arr.pop_back();
            
            accessed[i] = 0;
        }
    }
    
    return 0;
}
