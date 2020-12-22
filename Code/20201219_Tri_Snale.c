#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {

    int* answer = (int*)calloc(n * (n+1) / 2, sizeof(int));
    int *point = answer;

    // 값 입력을 위한 index
    int idx_snale = 1;

    // 현재 층수를 판단하기 위한 index
    int idx_hier = 1;

    // 최대로 갈 수 있는 가장 높은 층 index
    int max_depth = n;
    
    // 최저로 갈 수 있는 가장 낮은 층 index
    int min_depth = 2;

    // 증가, 감소를 알 수 있는 flag - 0: 증가, 1: 감소
    int inc_dec = 0;

    // 최대 달팽이 index까지 반복
    while(idx_snale <= (n * (n+1) / 2)){
        
        *point = idx_snale;

        if(inc_dec == 0){
            // 최대 깊이일 때
           if(idx_hier == max_depth){
               // 가장 깊은 깊이일 때 column 이동
               for(int c_idx = 0; c_idx < idx_hier-1; c_idx++ ){
                   
                   // 커서와 값 증가
                   point++;
                   idx_snale++;

                   // 값이 없는 경우(0인 경우)만 값 삽입
                   if(*(point) == 0){
                       *point = idx_snale;
                   }else{
                       point--;
                       idx_snale--;
                   }
               }

               // 증감 flag를 감소(1)로 변경
               inc_dec = 1;

               // 매 반복마다 최대 깊이가 바뀌어야 함(감소)
               max_depth--;

               // 다음번의 위치 및 삽입할 값 지정
               point -= idx_hier;
               idx_hier--;
               idx_snale++;
               continue;
           }else{
            // 최대 깊이가 아닌 단순 층 증가일 때
            // 현재 층수만큼 증가    
            point += idx_hier;

            // 사용 후 층수도 따라 증가
            idx_hier++;
           }
        }else if(inc_dec == 1){
            // 감소 flag일 때의 동작
            if(idx_hier == min_depth){
                // 최소 깊이에 도달했을 때
                inc_dec = 0;
                
                // 최대와 달리 최소는 2씩 증가
                min_depth += 2;

                point += idx_hier;
                idx_hier++;
                idx_snale++;
                continue;
            }

            // 현재 층수만큼 감소
            point -= idx_hier;

            // 사용 후 층수도 따라 감소
            idx_hier--;
        }

        // 달팽이 배열 다음 값으로 증가
        idx_snale++;
    }    
    return answer;
}
