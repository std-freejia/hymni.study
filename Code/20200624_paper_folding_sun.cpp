#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int* solution(int n) {
    // return할 변수는 malloc을 이용해서 초기화해야합니다.
    int* answer;
    int axis = 0;
    int index = 0;
    int counter = 0;
    
    answer = (int*)malloc(sizeof(int) * ((int)pow(2, n) - 1));
    
    while(axis < n)
    {
        index = (int)pow(2, axis) - 1;
        
        counter = index;
        
        answer[index] = 0;
        
        while(counter)
        {
            answer[++index] = !answer[--counter];
        }
        
        axis++;
    }
    
    return answer;
}
