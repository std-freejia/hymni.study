#include <string>
#include <vector>
using namespace std;

// 스킬트리 

int solution(string skill, vector<string> skill_trees) {

	int skill_len = skill.length(); // 스킬순서의 길이 "CBD" 
	int answer = 0;

	for (int i = 0; i < skill_trees.size(); i++) {
		string str = skill_trees[i]; // 문자열 1개에 대하여 "BACDE"
		vector<int> v; // 

		for (int j = 0; j < str.size(); j++) {
			
			int idx = skill.find(str[j]); //str의 문자 가지는 스킬순서의 인덱스  
 			if (idx != -1) v.push_back(idx); // str의 문자가 스킬순서에 존재하지 않으면 -1 
			
			// 스킬순서 "CBD", 문자열 "BACDE" 일 때, 
			// idx 는 {1 -1, 0, 2, -1}   
			// v에 저장되는 것 {1, 0, 2}
		}

		bool flag = true;

		for (int k = 0; k < v.size(); k++) {
			if (v[k] != k) {
				flag = false; break;
			}
		}

		if (flag) answer++;
	}
    
    
    return answer;
}