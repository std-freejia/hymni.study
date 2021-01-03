#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    // nCr의 조합일 때 최대 갯수
    int totalLength = (numbers_len * (numbers_len-1)) / 2;

    int* tmp = (int*)malloc(sizeof(int) * totalLength);
    int* answer = (int*)malloc(sizeof(int) * totalLength);
    
    // tmp에 모든 경우의 수 계산, 삽입
    int tmpIdx = 0;
    for(int arrIdx = 0; arrIdx < numbers_len - 1; arrIdx++){
        for(int subIdx = arrIdx + 1; subIdx < numbers_len; subIdx++){
            tmp[tmpIdx] = numbers[arrIdx] + numbers[subIdx];
            tmpIdx++;
        }
    }
    
    // 중복수 점검을 위한 정렬 과정
    qsort(tmp, totalLength, sizeof(int), compare);
    tmpIdx = 0;
    for(int arrIdx = 0; arrIdx < totalLength; arrIdx++){

        // 중복 무시
        if((arrIdx != totalLength - 1) && (tmp[arrIdx] == tmp[arrIdx+1])){
            continue;
        }
        
        // 중복을 제외한 나머지를 answer 배열에 삽입
        answer[tmpIdx] = tmp[arrIdx];
        tmpIdx++;

    }
    
    
    free(tmp);
    return answer;
}