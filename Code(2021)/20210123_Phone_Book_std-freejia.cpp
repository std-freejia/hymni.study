#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 전화번호 목록 

bool solution(vector<string> phone_book) {
    bool answer = true;
    int vsize = phone_book.size();
    
    sort(phone_book.begin(), phone_book.end()); // 오름차순 정렬 
    
    for (int i = 0; i < vsize-1; i++) { 
        for (int j = i+1; j < vsize; j++) {

            if (phone_book[j].find(phone_book[i], 0) == 0) { // phone_book[i]가 접두사인지(인덱스 0)확인.
                return false;
            }
        }
    }

    return answer;
}
