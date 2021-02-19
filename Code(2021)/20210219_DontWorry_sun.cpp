#include <iostream>
#include <cmath>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	int A = 0;
	int B = 0;
	int D = 0;
	
	cin >> T;
	
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		
		cin >> A >> B >> D;
		
		Answer = ceil((double)(D - A) / (A - B));
		
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer + 1 << endl;
	}

	return 0;
}
