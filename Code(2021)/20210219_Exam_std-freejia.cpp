#include <iostream>
#include <vector>
#include <algorithm>  // sort()
#include <functional> // greater 
#include <numeric>  // partial_sum()
using namespace std;


// 시험 공부  --100점 

int Answer, n, N, K;

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
	    cin >> N >> K; //
	    vector<int> v;
	    vector<int> psum(N+1);
	    
	    while(N--){
	        cin >> n; 
	        v.push_back(n);
	    }
	    
		// 벡터 v를 내림차순 정렬
	    sort(v.begin(), v.end(), greater<int>());
	
		// v의 부분합 구해서 psum에 저장 
	    partial_sum(v.begin(), v.end(), psum.begin());
	
	    Answer = psum[K-1];
	    
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
