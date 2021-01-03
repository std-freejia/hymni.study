#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int solution(int n) {
    int answer = 0;
    
    // log3(n)
    int maxLog = log(n) / log(3);
    int tmp;
    
    int remainNum = n;
    for(int iterIdx = maxLog; iterIdx >= 0; iterIdx--){
        // 3의 최대 제곱수 부터 차례로 몫 계산
        tmp = remainNum / pow(3,iterIdx);

        // 동시에 자리수를 바꾸어 게산
        answer += (int)pow(3, maxLog-iterIdx) * tmp;

        // 남은 수를 계속 나누며 나머지 연산
        remainNum %= (int)pow(3,iterIdx);
    }
    
    return answer;
}