#include <stdio.h>
#include <stdlib.h>
 
//BAEKJOON 2667, 단지번호붙이기, LDH
 
int vectX[4] = { 0, 0, 1, -1 };
int vectY[4] = { 1, -1, 0, 0 };
 
int map[26][26];
int house_size = 0;
int house_cnt = 0;

int house[26*(26 / 2) + 1];		//단지를 저장할 배열, 단지 최대 개수 -> n * (n/2) + 1

int compare(const void *a, const void *b);
int dfs(int x, int y, int key);
int solution();
 
int main()
{
    scanf("%d", &house_size);
	
    for(int i = 0; i < house_size; i++)
	{
        for(int j = 0; j < house_size; j++)
		{
            scanf("%1d", &map[i][j]);
        }
    }
 
    solution();
    
	printf("%d\n", house_cnt);
    
	qsort(house, sizeof(house)/sizeof(int), sizeof(int), compare);
	
    for(int i = 0; i < house_cnt; i++)
	{
        printf("%d\n", house[i]);
    }
}

int dfs(int x, int y, int key)
{
    map[x][y] = key;	//key : 단지 개수를 의미, 최종 단지의 개수
 
    int nextX; int nextY;
    for(int i = 0; i < 4; i++)
	{
        nextX = x + vectX[i];
        nextY = y + vectY[i];
 
        if(nextX >= 0 && nextY >= 0 && nextX < house_size && nextY < house_size)
		{
            //printf("map[%d][%d] = %d\n", nextX, nextY, map[nextX][nextY]);
            if(map[nextX][nextY] == 1)
			{
                //좌표가 범위 안에 있으며 (x, y) 에서 (nextX, nextY)까지 가는 길이 있는 경우
				dfs(nextX, nextY, key);
            }
        }
    }
	
	return 0;
}

int solution()
{
    for(int i = 0; i < house_size; i++)
	{
        for(int j = 0; j < house_size; j++)
		{
            if(map[i][j] == 1)
			{
                house_cnt++;
                dfs(i, j, house_cnt+1);
            }
        }
    }
 
    for(int i = 0; i < house_size; i++)
	{
        for(int j = 0; j < house_size; j++)
		{
            if(map[i][j] > 1)
			{
                house[map[i][j] - 2] ++;
            }
        }
    }
	
	return 0;
}

//퀵정렬 비교함수
int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if(num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if(num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}
