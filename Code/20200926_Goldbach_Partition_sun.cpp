#include <iostream>
#include <cmath>

using namespace std;

const int MAX_T = 100;
const int MAX_N = 1000000;
int result[MAX_T] = {0};
int prime_num[MAX_N + 1] = {0};

int is_prime();
int Goldbach_Partition(int N);

int main(int argc, char* argv[], char* envs[])
{
    int T = 0;
    int N = 0;
    
    is_prime();
    
    cin>>T;
    
    for(int i=0; i<T; i++)
    {
        cin>>N;
        
        result[i] = Goldbach_Partition(N);
    }
    
    for(int i=0; i<T; i++)
    {
        cout<<result[i]<<"\n";
    }
    
    return 0;
}

int is_prime()
{
    for(int i=2; i<=MAX_N; i++)
    {
        if(prime_num[i] == 0)
        {
            prime_num[i] = 1;
            
            for(int j=2*i; j<=MAX_N; j+=i)
            {
                prime_num[j] = -1;
            }
        }
    }
    
    return 0;
}

int Goldbach_Partition(int N)
{
    int counter = 0;
    
    for(int i=2; i<=N/2; i++)
    {
        if(prime_num[i] == 1 && prime_num[N - i] == 1)
        {
            counter++;
        }
    }
    
    return counter;
}
