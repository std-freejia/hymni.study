#include <string>
#include <vector>
using namespace std;

// 체육복 

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    int answer = n;

    vector<int> student(n+1, 1); // 1로 초기화 

    
    for (auto i : reserve) { // 여벌 있으면 + 1 
        student[i]++;
    }

    for (auto i : lost) { // 도난 당했다면 -1
        student[i]--;
        if (student[i] == 0) answer--;
    }

    for (int i = 1; i < n; i++) { // 빌려줄 수 있는 경우는 (2, 0) 그리고 (0, 2) 인 경우 뿐이다. 

        if (student[i] == 2 && student[i+1] == 0) {
            student[i] = student[i + 1] = 1;
            answer++;
            
        }else if(student[i] == 0 && student[i + 1] == 2) {
            student[i] = student[i + 1] = 1;
            answer++;
        }
    }

    return answer;
}