#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ' ')
        {
            idx = 0;
            
            continue;
        }
        
        if(idx % 2 == 0)
        {
            if('a' <= s[i] && s[i] <= 'z')
            {
                s[i] -= 32;
            }
        }
        else
        {
            if('A' <= s[i] && s[i] <= 'Z')
            {
                s[i] += 32;
            }
        }
        
        idx++;
    }
    
    answer = s;
    
    return answer;
}
