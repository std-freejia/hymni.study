/* 
1. 유클리드 호제법으로 최대공약수 계산
2. 최소공배수 = 곱 / 최대공약수
*/

#include <iostream>

using namespace std;

int GCD(int num1, int num2);
int LCM(int num1, int num2);

int main(int argc, char* argv[], char* envs[])
{
    int num1 = 0;
    int num2 = 0;
    
    cin>>num1>>num2;
    
    cout<<GCD(num1, num2)<<"\n";
    
    cout<<LCM(num1, num2);
    
    return 0;
}

int GCD(int num1, int num2)
{
    // 유클리드 호제법
    
    if(num1 % num2 == 0)
    {
        return num2;
    }
    else
    {
        return GCD(num2, num1 % num2);
    }
}

int LCM(int num1, int num2)
{
    // 최소공배수 = 곱 / 최대공약수
    
    return ((num1 * num2) / GCD(num1, num2));
}
