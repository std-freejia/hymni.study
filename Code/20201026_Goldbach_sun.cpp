#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
int checked[MAX + 1] = {0};
vector<int> prime_num;

int is_prime();
int Goldbach(int num);

int main(int argc, char* argv[], char* envs[])
{
    int num = 0;
    
    is_prime();
    
    scanf("%d", &num);
    
    while(num)
    {
        Goldbach(num);
        
        scanf("%d", &num);
    }
    
    return 0;
}

int is_prime()
{
    for(int i=2; i<=MAX; i++)
    {
        if(!checked[i])
        {
            checked[i] = 1;
            prime_num.push_back(i);
            
            for(int j=2*i; j<=MAX; j+=i)
            {
                checked[j] = -1;
            }
        }
    }
    
    return 0;
}

int Goldbach(int num)
{
    for(int i=0; prime_num[i]<=num/2; i++)
    {
        if(checked[num - prime_num[i]] == 1)
        {
            printf("%d = %d + %d\n", num, prime_num[i], num - prime_num[i]);
            
            return 0;
        }
    }
    
    printf("Goldbach's conjecture is wrong.\n");
    
    return 0;
}
