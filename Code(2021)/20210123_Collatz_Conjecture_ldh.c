#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {
    
	//프로그래머스, 콜라츠 추측, LDH
	long answer = num;
    
    for(int i = 0; i < 500; i++)
    {
        if(answer == 1)	//결과값이 1인 경우 종료, 반복횟수 리턴
        {
            return i;
        }
        else if(answer%2 == 0)	//짝수이면 2로 나누기
        {
            answer /= 2;
        }
        else	//홀수이면 3곱하고 1더하기
        {
            answer = (answer*3) + 1;
        }
    }
    
    return -1;
}
