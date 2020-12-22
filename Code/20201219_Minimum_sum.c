#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// for study
// bubble sort
void bubble_sort_nama(int *arr, int arr_len){
	int tmp;
    
	for(int idx = 0; idx < arr_len - 1; idx++){
		for(int s_idx = 0; s_idx < arr_len - idx - 1; s_idx++){
            if(arr[s_idx] == arr[s_idx+1])
                continue;
			if(arr[s_idx] > arr[s_idx+1]){
				tmp = *(arr + s_idx);
				*(arr+s_idx) = *(arr+s_idx+1);
				*(arr+s_idx+1) = tmp;
			}
		}
	}
}

int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;
    // qsort(A, A_len, sizeof(int), compare);
    // qsort(B, B_len, sizeof(int), compare);

    // 정렬 후 한쪽은 최대부터 한쪽은 최소부터 곱하여 더함   
    bubble_sort_nama(A, A_len);
    bubble_sort_nama(B, B_len);
    
    for(int sum_idx = 0; sum_idx < A_len; sum_idx++){
		answer += (A[sum_idx] * B[B_len-1-sum_idx]);
	}
    
    return answer;
}