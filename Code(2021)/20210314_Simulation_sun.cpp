#include <vector>
#include <algorithm>

using namespace std;

const int person1[5] = {1, 2, 3, 4, 5};
const int person2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
const int person3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int score[4] = {0};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int max_score = 0;
    int i = 0;  // for loop
    
    for(i=0; i<answers.size(); i++)
    {
        if(person1[i % 5] == answers[i])
        {
            score[1]++;
        }
        
        if(person2[i % 8] == answers[i])
        {
            score[2]++;
        }
        
        if(person3[i % 10] == answers[i])
        {
            score[3]++;
        }
    }
    
    max_score = *max_element(score, score + 4);
    
    for(i=1; i<4; i++)
    {
        if(score[i] == max_score)
        {
            answer.push_back(i);
        }
    }
    
    return answer;
}
