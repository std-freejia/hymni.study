#include <vector>
#include <algorithm>

using namespace std;

const int diff[3] = {0, -1, 1};

int solution(int n, vector<int> lost, vector<int> reserve) {
    int i = 0;  // for loop
    int j = 0;  // for loop
    int answer = n;
    vector<int>::iterator it;
    
    for(i=0; i<lost.size(); i++)
    {
        // 본인, 바로 앞번호, 바로 뒷번호 순으로 체크
        for(j=0; j<3; j++)
        {
            // 바로 뒷번호 학생에게 빌릴 수 있는지
            if(j == 2 && lost[i + 1] == lost[i] + 1)
            {
                continue;
            }
                        
            it = find(reserve.begin(), reserve.end(), lost[i] + diff[j]);
            
            if(it != reserve.end())
            {
                reserve.erase(it);
            
                break;
            }
        }
        
        if(j == 3)
        {
            answer--;
        }
    }
    
    return answer;
}
