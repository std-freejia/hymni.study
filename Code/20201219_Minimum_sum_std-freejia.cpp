#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	int asize = A.size();
	for (int i = 0; i < asize; i++)
		answer += (A[i] * B[B.size() - i - 1]); 
	return answer;
}