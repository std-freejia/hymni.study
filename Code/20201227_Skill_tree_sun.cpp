#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int i = 0;  // for loop
    int j = 0;  // for loop
    
    for(i=0; i<skill_trees.size(); i++)
    {
        // 순서에 없는 다른 스킬을 제거
        for(j=0; j<skill_trees[i].size(); j++)
        {
            if(skill.find(skill_trees[i][j]) == string::npos)
            {
                skill_trees[i].erase(j, 1);
                j--;
            }
        }
        
        // 선행 스킬 순서 skill과 유저들이 만든 스킬 순서 비교
        if(skill_trees[i] == skill.substr(0, skill_trees[i].size()))
        {
            answer++;
        }
    }
    
    return answer;
}
