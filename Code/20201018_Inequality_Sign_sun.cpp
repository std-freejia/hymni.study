/*
1. 일반 재귀법 사용
2. 최대/소값을 0/9876543210으로 설정하고 재귀하면서 갱신
3. long long int 형 주의
4. 정수값을 재귀하면서 result = result * 10 + bit로 계산
*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_k = 9;
int k = 0;
int num[10] = {0};  // 0~9
char sign[MAX_k] = {0};
long long max_result = 0;  // 최대값을 0으로 초기화
long long min_result = 9876543210;  // 최소값을 9876543210으로 초기화

int find_seq(int counter, long long result);

int main(int argc, char* argv[], char* envs[])
{
    int i = 0;
    
    cin>>k;
    
    for(i=0; i<k ;i++)
    {
        cin>>sign[i];
    }
    
    int counter = 1;
    long long result = 0;
    
    for(i=0; i<10; i++)
    {
        result = i;
        
        num[i] = 1;
        find_seq(counter, result);
        num[i] = 0;
    }
    
    if(max_result < pow(10, k))
    {
        cout<<'0';
    }
    cout<<max_result<<"\n";
    
    if(min_result < pow(10, k))
    {
        cout<<'0';
    }
    cout<<min_result<<"\n";
    
    return 0;
}

int find_seq(int counter, long long result)
{
    if(counter == k + 1)
    {
        max_result = max(max_result, result);
        min_result = min(min_result, result);
        
        return 0;
    }
    
    int pre = 0;
    
    for(int i=0; i<10; i++)
    {
        if(!num[i])
        {
            pre = result % 10;
            
            if(pre > i && sign[counter - 1] != '>' ||
               pre < i && sign[counter - 1] != '<')
            {
                continue;
            }
            
            num[i] = 1;
            find_seq(counter + 1, result * 10 + i);
            num[i] = 0;
        }
    }
    
    return 0;
}
