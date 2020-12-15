#include <string>
#include <vector>

const int max = 100000;
int Fibo[max + 1] = {0};

using namespace std;

int solution(int n) {
    int answer = 0;

    Fibo[0] = 0;
    Fibo[1] = 1;

    for(int i=2; i<=n; i++)
    {
        Fibo[i] = (Fibo[i - 1] + Fibo[i - 2]) % 1234567;
    }

    answer = Fibo[n];

    return answer;
}
