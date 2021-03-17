#include <string>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int move = 0;  // 죄우 이동 횟수
    int left = 0;  // 왼쪽 가장 가까운 바꿀 위치
    int right = 0;  // 오른쪽 가장 가까운 바꿀 위치
    int cursor = 0;
    int len = name.size();
    string init(len, 'A');
    
    while(1)
    {
        answer += min(name[cursor] - 'A', 'Z' - name[cursor] + 1);
        init[cursor] = name[cursor];
        
        if(init == name)
        {
            break;
        }
        
        for(move=1; move<=len/2; move++)
        {
            left = (cursor - move + len) % len;
            right = (cursor + move) % len;
            
            if(init[right] != name[right])
            {
                answer += move;
                cursor = right;
                break;
            }
            
            if(init[left] != name[left])
            {
                answer += move;
                cursor = left;
                break;
            }
        }
    }
    
    return answer;
}
