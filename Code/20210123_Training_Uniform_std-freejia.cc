#include <string>
#include <vector>

using namespace std;


int solution(int n, vector<int> lost, vector<int> reserve) {
    
    int answer = n;

    vector<int> student(n+1, 1); // 1로 초기화 

    for (int i = 0;  i < reserve.size(); i++) { // 여벌 있으면 + 1 
        student[reserve[i]]++;
    }

    for (int i = 0; i < lost.size(); i++) { // 도난 당했다면 -1
        student[lost[i]]--;
        if (student[lost[i]] == 0) answer--;
    }


    for (int i = 1; i < n; i++) {

        if (student[i] == 2 && student[i+1] == 0) {
            student[i] = student[i + 1] = 1;
            answer++;
            continue;
        }else if(student[i] == 0 && student[i + 1] == 2) {
            student[i] = student[i + 1] = 1;
            answer++;
            continue;
        }
    }

    return answer;
}