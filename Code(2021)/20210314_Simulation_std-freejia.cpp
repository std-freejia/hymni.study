#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 모의고사
// 패턴 돌아옴을 이용 
int first[] = {1, 2, 3, 4, 5};
int second[] = {2, 1, 2, 3, 2, 4, 2, 5};
int third[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    
	vector<int> answer;
	vector<int> score = {0, 0, 0};
	
	int len_answer = answers.size();
	int i = 0, max_score = 0;
	
	for(i=0; i<len_answer; i++){
	
		if(answers[i] == first[i%5]) score[0]++;
				
		if(answers[i] == second[i%8]) score[1]++;
		
		if(answers[i] == third[i%10]) score[2]++;
		
	}
	// 셋 중에 최대값  
	max_score = max(score[0], max(score[1], score[2]) );
	
	for(i=0; i<3; i++){
		if(max_score == score[i]) {
			answer.push_back(i+1);
		}
	}
	
	return answer;
}