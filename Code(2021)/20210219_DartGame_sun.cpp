#include <iostream>
#include <cmath>

using namespace std;

int scores[20] = {6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10};
int Answer;
const double PI = 3.14159265;

int main(int argc, char** argv)
{
	int T, test_case;
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	int E = 0;
	int N = 0;
	int x = 0;
	int y = 0;
	int score = 0;
	double r = 0;
	double deg = 0;
	
	cin >> T;
	
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		
		cin >> A >> B >> C >> D >> E;
		
		cin >> N;
		
		while(N--)
		{
		    cin >> x >> y;
		    
		    r = sqrt(x * x + y * y);
		    deg = atan2(y, x) * 180 / PI;
		    
		    deg += 9;
		    deg < 0 ? deg += 360 : 0;
		    
		    score = scores[(int)deg / 18];
		    
		    if(r <= A)
		    {
		        Answer += 50;
		    }
		    else if(B <= r && r <= C)
		    {
		        Answer += 3 * score;
		    }
		    else if(D <= r && r <= E)
		    {
		        Answer += 2 * score;
		    }
		    else if(r <= E)
		    {
		        Answer += score;
		    }
		}
		
		cout << "Case #" << test_case + 1 << "\n";
		cout << Answer << "\n";
	}

	return 0;
}
