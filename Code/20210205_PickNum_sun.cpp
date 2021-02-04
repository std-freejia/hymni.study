#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;
	int N = 0;
	int i = 0;  // for loop
	unsigned int num = 0;
	unsigned int Answer = 0;

	cin >> T;
	
	for(test_case = 0; test_case < T; test_case++)
	{
    Answer = 0;
	    
		cin >> N;
		
		for(i=0; i<N; i++)
		{
		    cin >> num;
		    
		    Answer ^= num;
		}
		
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
