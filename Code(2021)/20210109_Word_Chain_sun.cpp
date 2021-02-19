#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    map<string, int> word;
    
    word[words[0]] = 1;
    
    for(int i=1; i<words.size(); i++)
    {
        if(word.count(words[i]) > 0 || words[i].front() != words[i - 1].back())
        {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        
        word[words[i]] = 1;
    }

    return answer;
}
