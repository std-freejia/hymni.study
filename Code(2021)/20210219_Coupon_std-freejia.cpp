#include <iostream>
#include <algorithm>
using namespace std;


// 할인권 --100점  


int Answer, n, m, k; 
int a, b, c, p, s, e;
int cost[101][101];

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		cin >> n >> m >> k;  // 정거장 개수, 경로 개수, 할인권 비용 

		// 2차원 배열 초기화 fill( 배열의 시작 주소, 종료 주소, 값 )
		fill(cost[0], cost[0] + (101*101), 1e6);
	
		while (m--) { // 존재하는 경로의 비용 
			cin >> a >> b >> c;
			cost[a][b] = cost[b][a] = c;
		}

		for (int i = 1; i <= n; i++) {// 존재하지 않는 경로의 비용 0 
			cost[i][i] = 0;
		}

		// cost 테이블 채우기 (플로이드 워샬)
		for (int c = 1; c <= n; c++) { // N개의 정거장 
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cost[i][j] = min(cost[i][j], cost[i][c] + cost[c][j]);
				}
			}
		}
		
		cin >> p; // 여행 계획 경로 
		
		while (p--) {
			cin >> s >> e;
			if (cost[s][e] > k) { // 할인권 보다 비싸다면 Answer++
				Answer++;
			}
		}
		
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
