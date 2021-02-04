#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	int N = 0;
	int num = 0;
	int i = 0;  // for loop
	vector<int> A;
	
	cin >> T;
  
	for(test_case = 0; test_case < T; test_case++)
	{
    A.clear();
		Answer = 0;
		
		cin >> N;
		
		for(i=0; i<N; i++)
		{
		    cin >> num;
		    A.push_back(num);
		}
		
		sort(A.begin(), A.end());
		
		for(i=0; i<N; i++)
		{
		    Answer += (A[i] * (i & 1 ? -1 : 1));
		}
		
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
