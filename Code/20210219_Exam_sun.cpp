#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	int N = 0;
	int K = 0;
	int score;
	multiset<int, greater<int>> scores;
	multiset<int, greater<int>>::iterator it;

	cin >> T;
	
	for(test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		scores.clear();
		
		cin >> N >> K;
		
		while(N--)
		{
		    cin >> score;
		    scores.insert(score);
		}
		
		it = scores.begin();
		
		while(K--)
		{
		    Answer += *it;
		    it++;
		}
		
		cout << "Case #" << test_case + 1 << "\n";
		cout << Answer << "\n";
	}

	return 0;
}
