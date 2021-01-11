#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    int i = 0;  // for loop
    int len = 0;
    
    while(s != "1")
    {
        len = 0;
        answer[0]++;
        
        // 0 세기
        for(i=0; i<s.size(); i++)
        {
            if(s[i] == '0')
            {
                len++;
            }
        }
        
        answer[1] += len;
        len = s.size() - len;
        s.clear();
        
        // 이진 변환
        while(len)
        {
            s += (len & 1) + '0';
            len = len >> 1;
        }
    }
    
    return answer;
}
