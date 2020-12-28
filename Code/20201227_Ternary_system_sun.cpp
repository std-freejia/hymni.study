#include <string>
#include <cmath>

using namespace std;

const int DIVISOR = 3;  // 3진법

int solution(int n) {
    int answer = 0;
    string s = "";  // 앞뒤 반전 3진법 저장
    
    // 앞뒤 반전 3진법 계산
    while(n)
    {
        s += (n % DIVISOR);
        
        n /= DIVISOR;
    }
    
    // 10진법으로 표현
    for(int i=0; i<s.size(); i++)
    {
        answer += (s[i] * pow(DIVISOR, s.size() - i - 1));
    }
    
    return answer;
}
