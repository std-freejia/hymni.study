#include <string>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n)
    {
        if(n % 3 == 0)
        {
            answer += '4';
            n =  n / 3 - 1;
        }
        else
        {
            answer += n % 3 + '0';
            n /= 3;
        }
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
