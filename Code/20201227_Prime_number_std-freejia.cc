#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<bool> prime; // 소수 표시할 배열 (초기값 전부 1)

void prime_check(int num) {

	prime[0] = prime[1] = 0; 

	for (int i = 2; i*i <= num; i++) {

		if (prime[i]) { // 소수의 배수를 전부 0 로 처리 
			for (int j = i * i; j <= num; j += i) {
				prime[j] = 0;
			}
		}
	}

	return;
}

int solution(vector<int> nums) {

    int n_size = nums.size(); // 벡터 크기
	int answer = 0;

	// 배열 크기와 초기값 지정 
	prime.assign(3001, 1);
	
	// 가장 큰 숫자까지 소수 더하기 
	prime_check(3000);

	// 3중 for문 조합
	for (int i = 0; i < n_size; i++) {
		for (int j = i+1; j < n_size; j++) {
			for (int k = j+1; k < n_size; k++) {

				int sum = nums[i] + nums[j] + nums[k];

				if (prime[sum]) {
					answer++;
				}
			}
		}
	}

    return answer;
}