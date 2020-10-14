#include <iostream>

using namespace std;

int GCD(int num1, int num2);
int LCM(int num1, int num2);

int main(int argc, char* argv[], char* envs[])
{
    int num1 = 0;
    int num2 = 0;
    int gcd = 0;
    
    cin>>num1>>num2;
    
    cout<<GCD(num1, num2)<<"\n";
    
    cout<<LCM(num1, num2);
    
    return 0;
}

int GCD(int num1, int num2)
{
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
    return ((num1 * num2) / GCD(num1, num2));
}
