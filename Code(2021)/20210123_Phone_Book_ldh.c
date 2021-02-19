#include <string>
#include <vector>
#include <algorithm>    //sort 함수 정의

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    //프로그래머스, 전화번호 목로, LDH    
    sort(phone_book.begin(), phone_book.end());     //string 오름차순 정렬
    
    for(int i = 0; i < phone_book.size()-1; i++)
    {
        if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size()))    //인접한 전화번호를 같은 자리수로 비교
        {
            answer = false;
        }
    }
    
    return answer;
}
