#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	int N = 0;
	
	cin >> T;
	
	for(test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		
		cin >> N;
		
		while(N)
		{
		    Answer += (N & 1);
		    N = N >> 1;
		}
		
		cout << "Case #" << test_case + 1 << "\n";
		cout << Answer << "\n";
	}

	return 0;
}
