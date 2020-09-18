#include <stdio.h>

//BAKJOON 2133, Fill Tile, 200918 LDH

int main(int argc, char* argv[], char*env[])
{
	int result[31] = {0,};	//3xN의 값들을 순차적으로 넣을 배열선언
    int N = 0;

    scanf("%d", &N);

    result[0] = 1;	//3x0 계산을 위한 초기값

    for (int i = 2; i <= N; i += 2)
    {
        result[i] = result[i-2] * 3;	//앞 전 *3
		
        for (int j = i - 4; j >= 0; j -= 2)
		{
            result[i] = result[i] + result[j] * 2;		//앞 전전 *2
		}
    }
	
	/*
		N->2 경우 3x2 result : 3
		N->4 경우 N->2값*3 + N->0*2
	*/

    printf("%d", result[N]);
	
    return 0;
}