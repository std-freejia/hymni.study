#include <string>
#include <cctype>

using namespace std;

string solution(string s) {
    int idx = 0;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ' ')
        {
            idx = 0;
        }
        else
        {
            s[i] = (idx & 1 ? tolower(s[i]) : toupper(s[i]));
            idx++;
        }
    }
    
    return s;
}
