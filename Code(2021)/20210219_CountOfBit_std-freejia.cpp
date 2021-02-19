#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;


// 1비트 개수 세기  -- 100점

int Answer, N;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
	
	    cin >> N;
	    
		// 길이 32의 2진수로 바꿔서 문자열로 저장 
        string st = bitset<32>(N).to_string();
        
		// 문자 1의 개수 센다 
        Answer = count(st.begin(), st.end(), '1');
	
		cout << "Case #" << test_case+1 << '\n';
		cout << Answer << '\n';
	}

	return 0;
}
