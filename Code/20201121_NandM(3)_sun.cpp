#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int M = 0;
vector<int> seq;

int combination(int counter);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    
    int counter = 0;
    
    combination(counter);
    
    return 0;
}

int combination(int counter)
{
    if(counter == M)
    {
        for(int i=0; i<M; i++)
        {
            cout<<seq[i]<<" ";
        }
        cout<<"\n";
        
        return 0;
    }
    
    for(int i=1; i<=N; i++)
    {
        seq.push_back(i);
        combination(counter + 1);
        seq.pop_back();
    }
    
    return 0;
}
