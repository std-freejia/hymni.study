#include <string>
#include <vector>
using namespace std;

// 하샤드 수 

int i, sum, x_old;

bool solution(int x) {

    bool answer = true;
    x_old = x;
    
    while(x){
    	sum += (x % 10);
    	x /= 10;
	}
	
	if(x_old % sum != 0){
		answer = false;
	}
    
    return answer;
}