#include <vector>

using namespace std;

const int MAX = 1000;
vector<bool> prime(3 * MAX + 1, 1);

int find_prime(int N);

int solution(vector<int> nums) {
    int answer = 0;
    int i = 0;  // for loop
    int j = 0;  // for loop
    int k = 0;  // for loop
    
    find_prime(3 * MAX);
    
    // 정렬 브루트포스
    for(i=0; i<nums.size()-2; i++)
    {
        for(j=i+1; j<nums.size()-1; j++)
        {
            for(k=j+1; k<nums.size(); k++)
            {
                if(prime[nums[i] + nums[j] + nums[k]])
                {
                    answer++;
                }
            }
        }
    }

    return answer;
}

int find_prime(int N)
{
    int i = 0;  // for loop
    int j = 0;  // for loop
    
    for(i=2; i<=N; i++)
    {
        if(prime[i])
        {
            for(j=2*i; j<=N; j+=i)
            {
                prime[j] = 0;
            }
        }
    }
    
    return 0;
}
