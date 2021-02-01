/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


// 스타벅스 Starbucks

int Answer;

int main() {

	int T, test_case;
	int N, M, K, num;
	N = M = K = 0;
	vector<int> order, price;

    //freopen("input.txt", "rt", stdin);
	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		int sum = 0;
		
		// 인원 수. 커피종류. 예산. 
		cin >> N >> M >> K; 
		
		for (int i = 0; i < N; i++) {
			cin >> num;
			order.push_back(num);
		}
	
		for (int i = 0; i < M; i++) {
			cin >> num;
			price.push_back(num);
		}

		// 1부터 M까지 몇 개인지 세서 가격과 곱하기  
		for (int i = 1; i <= M; i++) {
			sum += count(order.begin(), order.end(), i) * price[i-1];
		}

		cout << "Case #" << test_case + 1 << '\n';
		string Answer = (sum <= K) ? "Y" : "N";
		cout << Answer << '\n';

		order.clear();
		price.clear();
	}
	
    return 0;
}
