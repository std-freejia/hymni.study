#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 구명보트 

int solution(vector<int> people, int limit) {

    int answer = 0; 
    int front = 0; // 맨 앞 인덱스 
    int back = people.size() - 1;  // 맨 뒤 인덱스 

    sort(people.begin(), people.end()); // 오름차순 정렬 


    while (front <= back) { //  양 끝 인덱스가 만날 때 까지 

        if (people[front] + people[back] <= limit && (back-front >= 1) ) {
            front++; back--;  // 인덱스 변화 :  앞에서는 증가, 뒤에서는 감소 
        }
        else { // 뒤에 큰 값만 제거 
            back--;
        }
        answer++;
    }

    return answer;
}
