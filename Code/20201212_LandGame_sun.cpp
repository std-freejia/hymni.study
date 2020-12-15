#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int score[MAX][4] = {0};
    int i = 0;  // for loop
    int j = 0;  // for loop
    int k = 0;  // for loop

    for(i=0; i<4; i++)
    {
        score[0][i] = land[0][i];
        answer = max(answer, score[0][i]);
    }

    for(i=1; i<land.size(); i++)
    {
        for(j=0; j<4; j++)
        {
            for(k=0; k<4; k++)
            {
                if(k != j)
                {
                    score[i][j] = max(score[i][j], score[i - 1][k]);
                }
            }

            score[i][j] += land[i][j];
            answer = max(answer, score[i][j]);
        }
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
