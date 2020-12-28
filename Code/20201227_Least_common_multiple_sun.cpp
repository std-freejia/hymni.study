#include <vector>

using namespace std;

int GCD(int a, int b);
int LCM(int a, int b);

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i=1; i<arr.size(); i++)
    {
        answer = LCM(answer, arr[i]);
    }
    
    return answer;
}

int GCD(int a, int b)
{
    return a % b == 0 ? b : GCD(b, a % b);
}

int LCM(int a, int b)
{
    return (a * b / GCD(a, b));
}
