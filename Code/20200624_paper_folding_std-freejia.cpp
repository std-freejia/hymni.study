#include <string>
#include <vector>
using namespace std;

// 종이접기 (프로그래머스) by std-freejia  

vector<int> rev(vector<int> begin){
	
	vector<int> temp;
	
	for(int i = begin.size() - 1; i >= 0; --i){
		temp.push_back(1 - begin[i]); // begin[i] 순서와 숫자를 뒤집는다.  001 -> 011
	}
	
	return temp; 
}

vector<int> solution(int n){
	
	vector<int> answer(1);
	
	if(n == 1) return answer;
	
	for(int i = 2; i <= n; ++i){
		
		vector<int> temp = rev(answer);
		answer.push_back(0); // 가운데는 반드시 0  
		
		for(int j = 0; j < temp.size(); ++j){
			answer.push_back(temp[j]);
		}
	}
	
	return answer;
}
