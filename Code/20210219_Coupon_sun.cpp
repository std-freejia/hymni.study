#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100;
int link[MAX + 1][MAX + 1];
int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	int N = 0;
	int M = 0;
	int K = 0;
	int A = 0;
	int B = 0;
	int C = 0;
	
	cin >> T;
	
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		
		cin >> N >> M >> K;
		
		for(A=1; A<=N; A++)
	    {
	        for(B=1; B<=N; B++)
	        {
	            link[A][B] = (A == B ? 0 : 1000000);
	        }
	    }
		
		while(M--)
		{
		    cin >> A >> B >> C;
		    
		    link[A][B] = C;
		    link[B][A] = C;
		}
		
		for(C=1; C<=N; C++)
		{
		    for(A=1; A<=N; A++)
		    {
		        for(B=1; B<=N; B++)
		        {
		            link[A][B] = min(link[A][B], link[A][C] + link[C][B]);
		        }
		    }
		}
		
		cin >> C;
		
		while(C--)
		{
		    cin >> A >> B;
		    
		    link[A][B] > K ? Answer++ : 0;
		}
		
		cout << "Case #" << test_case + 1 << "\n";
		cout << Answer << "\n";
	}

	return 0;
}
