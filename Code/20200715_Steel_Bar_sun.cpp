#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int index = 0;
    
    vector<char> brackets;
    
    while(arrangement[index])
    {
        if(arrangement[index] == '(')
        {
            brackets.push_back(arrangement[index]);
        }
        else
        {
            brackets.pop_back();
            
            if(arrangement[index-1] == '(')
            {
                answer += brackets.size();
            }
            else
            {
                answer++;
            }
        }
       
        index++;
    }
    
    return answer;
}
