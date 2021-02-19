#include <iostream>
using namespace std;


// 점프와 순간 이동 

int solution(int N)
{
    int battery = 0;

	while (N != 0) {

		if (N % 2 == 1) { //N이 홀수라면, 
			N--; 
			battery++;
		}else{ // N이 짝수라면, 
			N -= (N/2);
		}
	}
    
    return battery;
}
