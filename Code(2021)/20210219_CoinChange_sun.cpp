#include <iostream>

using namespace std;

int coin[4] = {10, 50, 100, 500};
int Answer[4] = {0};

int main(int argc, char** argv)
{
	int T, test_case;
	int total = 0;
	int i = 0;  // for loop
	
	cin >> T;
	
	for(test_case = 0; test_case < T; test_case++)
	{
		cin >> total;
		
		for(i=3; i>=0; i--)
		{
		    Answer[i] = total / coin[i];
		    
		    total %= coin[i];
		}
		
		cout << "Case #" << test_case + 1 << "\n";
		
		for(i=0; i<4; i++)
		{
		    cout << Answer[i] << ' ';
		}
		cout << "\n";
	}

	return 0;
}
