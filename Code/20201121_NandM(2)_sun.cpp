#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int M = 0;
vector<int> seq;

int combination(int counter, int current);

int main(int argc, char* argv[], char* envs[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    
    int counter = 0;
    int current = 0;
    
    combination(counter, current);
    
    return 0;
}

int combination(int counter, int current)
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
    
    for(int i=current+1; i<=N-M+counter+1; i++)
    {
        seq.push_back(i);
        combination(counter + 1, i);
        seq.pop_back();
    }
    
    return 0;
}
