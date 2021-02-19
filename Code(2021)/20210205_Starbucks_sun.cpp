#include <iostream>
#include <cstring>

using namespace std;

const int MAX_M = 20;
int Answer;

int main(int argc, char** argv)
{
  int T, test_case;
	int N = 0;
	int M = 0;
	int K = 0;
	int temp = 0;
	int i = 0;  // for loop
	int coffee[MAX_M + 1] = {0};

	cin >> T;
	
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
    memset(coffee, 0, sizeof(coffee));
        
		cin >> N >> M >> K;
        
		for(i=0; i<N; i++)
		{
		    cin>>temp;
		    
		    coffee[temp]++;
		}
		
		for(i=1; i<=M; i++)
		{
		    cin>>temp;
		    
		    Answer += (temp * coffee[i]);
		}
		
		cout << "Case #" << test_case + 1 << endl;
		cout << (Answer <= K ? 'Y' : 'N') << endl;
	}

	return 0;
}
