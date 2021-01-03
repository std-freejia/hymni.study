#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 소수 판단 함수
int IsPrime(int num){
    for(int idx = 2; idx < num; idx++){
        if(num % idx == 0){
            // 소수가 아닌 경우
            return 0;
        }
    }
    
    return 1;
}

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0;
    int totalLength = nums_len*(nums_len-1)*(nums_len-2) / (3*2);

    int *a = nums;
    int *b = nums+1;
    int *c = nums+2;
    int flag = 0;
    
    // 현재 포인터가 가리키는 원소들이 소수인지 판단
    while(flag == 0){
        if(IsPrime(*a+*b+*c)){
            answer++;
        }
        if(c != (nums+nums_len) - 1){
            c++;
        }else if(b != (nums+nums_len) - 2){
            b++;
            c = b + 1;
        }else if(a != (nums+nums_len) - 3){
            a++;
            b = a + 1;
            c = b + 1;
        }else{
            flag = 1;
        }  
    }
    return answer;
}