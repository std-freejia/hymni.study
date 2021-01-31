#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 징검다리 건너기 (KAKAO 인턴)


// 연속적으로 0 이 limit개 만큼 있는지 참/거짓 확인 
bool limit_check(vector<int> s, int mid, int limit) {

    int cnt = 0;

    for (auto i : s) { // 돌에서 mid를 뺀다 

        if (i - mid <= 0) {
            cnt++;
            if (cnt == limit)
                return true;
        }
        else {
            cnt = 0;
        }
    }

    return false;
}
 
int solution(vector<int> stones, int k) {
    
    // 다리를 건너는 사람 수를 탐색 (1명 이상 돌의 최대값 이하)
    int front = 1;
    int back = *max_element(stones.begin(), stones.end()); // 최대값 

    while (front <= back) { // 이분탐색 

        int mid = (front + back) / 2;

        // mid 명이 다리를 건넜을 때, 연속되는 0의 개수가 k개 만큼인지 검사 
        if (limit_check(stones, mid, k)) {
            back = mid - 1; // 숫자를 감소시킴 
        }
        else {
            front = mid + 1; // 숫자를 증가시킴
        }
    }

    return front;
}