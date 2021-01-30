#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 실패율 (2019 KAKAO)

// 만약 실패율이 같은 스테이지가 있다면,  작은 번호의 스테이지가 먼저 온다 

bool compare(pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second) return (a.first < b.first); 
    return (a.second > b.second) ;
}

vector<int> solution(int N, vector<int> stages) {
    
    vector<int> answer;
    vector<pair<int, double>> per; // <인덱스, 실패율>

    for (int i = 1; i <= N; i++) { // 스테이지 : 1부터 N까지 
        double a = count(stages.begin(), stages.end(), i);  // i에 위치한 사람 
        double b = count_if(stages.begin(), stages.end(), [i](int elem) { return elem >= i; });  // i 이상인 사람

        if (b == 0) { // 스테이지에 도달한 사람이 없으면, 실패율 0 
            per.push_back({i , 0 });
            continue;
        }

        double fail = a / b; 
        per.push_back({i, fail});
    }

    sort(per.begin(), per.end(), compare); // 정렬 함수에 따름.

    for (int i = 0; i < N; i++) { // 인덱스를 answer에 옮긴다 
        answer.push_back(per[i].first);
    }

    return answer;
}