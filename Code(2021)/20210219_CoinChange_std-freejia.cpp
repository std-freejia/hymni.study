#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 잔돈  -100점 

int Answer;
int a, b, c, d;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;

	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		cin >> Answer;
		// 동전 종류 4개 
		vector<int> v{500, 100, 50, 10};
		
		// 동전 개수 저장 
		vector<int> a(4, 0);
		
		for(int i = 0; i < 4; i++){
		    
			// 500원 부터 잔돈 개수를 센다 
		    while(Answer / v[i] > 0){
		        int temp = Answer / v[i];
		        a[i] += temp;
				// 금액을 빼준다 
		        Answer -= (v[i] * temp);
		    }
		}
		
		// 10원 부터 출력해야 하니까 벡터 a의 원소 순서를 뒤집는다 
	    reverse(a.begin(), a.end());
		
		cout << "Case #" << test_case+1 << endl;
		
		for(auto aa : a){
		    cout << aa << ' ';    
		}
		cout <<  '\n';
	}

	return 0;
}
