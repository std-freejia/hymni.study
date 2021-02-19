#include <string>
#include <vector>

using namespace std;

// 124 나라의 숫자 

string solution(int n) {
    string answer = "";

	while (n > 0) {
		
		if (n % 3 == 0) { // 0이 나올 때 4로 바꿔줌 
			answer = "4" + answer;
			n = (n / 3) - 1;  // 몫을 1개 빼줘야 124 가능 
		}
		else {
			answer =  to_string(n % 3) + answer; 
			n /= 3;
		}
	}
    
    return answer;
}
