#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {

    int answer = 0;
    vector<int> v; 

	while (n) { // n이 0보다 클 때 까지 
		v.push_back(n % 3);
		n /= 3;
	}

	int vsize = v.size(); // 0021 

	for (int i = vsize-1; i >= 0; i--) { // 3 2 1 0   // 0 1 2 3 
		answer += (v[i] * pow(3, vsize-1-i));	
	}
	
    return answer;
}