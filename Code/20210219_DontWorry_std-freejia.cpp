#include <iostream>
using namespace std;

// 태준이의 걱정  -- 100점 


int Answer;
long long A, B, D;

int main(int argc, char** argv)
{
	int T, test_case;
 
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		cin >> A >> B >> D;
		
		// 학교로 전진하는게 우선이니까 1분이 지난다고 본다.  
		Answer = (D-A) / (A-B) + 1;
		
		// 나누어  떨어지지 않는다면, 시간이 더 필요하다. 
		if( (D-A)%(A-B) > 0 ) Answer++;
		
		cout << "Case #" << test_case+1 << '\n';
		cout << Answer << '\n';
	}

	return 0; 
}