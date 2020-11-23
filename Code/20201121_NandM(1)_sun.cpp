#include <iostream>
#include <vector>

using namespace std;

const int MAX = 8;
int N = 0;
int M = 0;
int visited[MAX + 1] = {0};
vector<int> seq;

int combination(int counter);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int counter = 0;
    
    cin>>N>>M;
    
    combination(counter);
    
    return 0;
}

int combination(int counter)
{
    if(counter == M)
    {
        for(int i=0; i<seq.size(); i++)
        {
            cout<<seq[i]<<" ";
        }
        
        cout<<"\n";
        
        return 0;
    }
    
    for(int i=1; i<=N; i++)
    {
        if(!visited[i])
        {
            seq.push_back(i);
            visited[i] = 1;
            combination(counter + 1);
            visited[i] = 0;
            seq.pop_back();
        }
    }
    
    return 0;
}
