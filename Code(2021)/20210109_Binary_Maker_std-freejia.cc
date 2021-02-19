#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


// 이진 변환 반복하기
vector<int> solution(string s) {
    vector<int> answer;
    answer.resize(2); 

    while ("1" != s) {
        
        // '0'의 개수 세기
        int n = s.length();
        // 문자열 -> char배열
        char* char_array = (char*)malloc(sizeof(char) * s.length());
        strcpy(char_array, s.c_str());
        
        // '0'의 개수 더함 
        answer[1] += count(char_array, char_array + n, '0');
        // char배열 -> 문자열  
        s = char_array; 
        
        // '0'만 제거 
        s.erase(remove(s.begin(), s.end(), '0'), s.end());

        // 이진 변환 
        int stlen = s.size(); // 문자열 길이
        string con_st = "";

        while (stlen) { // 이진 변환 
            con_st =  ( to_string(stlen % 2) + con_st ) ;
            stlen /= 2;
        }

        s = con_st;  // 문자열 갱신 
        answer[0]++; // 이진 변환 횟수 더함

    }
    
    return answer;
}
