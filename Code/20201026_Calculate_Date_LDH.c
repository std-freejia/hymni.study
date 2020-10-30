#include <stdio.h>

//BAKJOON 1476, Calculate_Date, LDH

int main(int argc, char* argv[], char* env[])
{
	int year = 1;
	int E, S, M = 1;
	//int e, s, m = 1;
	
	scanf("%d %d %d", &E, &S, &M);	//입력
	
	while(1)
	{
		if((year-E)%15 == 0 && (year-S)%28 == 0 && (year-M)%19 == 0)
        {
			break;	//입력 조건 찾으면 while문 종료
        }
		
        year++;
        
        /*
		//시간초과 난 코드
		if(E == e && S == s && M == m)
		{
			break;
		}
		
		e++;
		s++;
		m++;
		
		if(e == 16)
		{
			e = 1;
		}
		if(s == 29)
		{
			s = 1;
		}
		if(m == 20)
		{
			m = 1;
		}
        */
	}

	printf("%d", year);

	return 0;
}