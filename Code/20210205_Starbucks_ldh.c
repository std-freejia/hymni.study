#include <stdio.h>

int Answer;

int main(void)
{
	int T, test_case;
	// freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

    int C[30] = {0,};   //원하는 커피
	int P[20] = {0,};   //커피당 가격

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		int N, M, K = 0;
	    int totalPrice = 0; //K와 비교할 총 커피값
	    
	    scanf("%d %d %d", &N, &M, &K);
	    
	    for(int i = 0; i < N; i++)
	    {
	        scanf("%d", &C[i]);     //커피 우선순위 저장
	    }
	    
	    for(int i = 0; i < M; i++)
	    {
	        scanf("%d", &P[i]);     //커피 가격 저장
	    }
	    
	    for(int i = 0; i < N; i++)
	    {
	        int c = C[i];           //i번째 사람의 원하는 커피
	        int p = P[c];           //i번째 사람의 원하는 커피 가격
	        totalPrice += p;
	    }
	    
	    if(totalPrice <= K)
	    {
	        Answer = 'Y';
	    }else
	    {
	        Answer = 'N';
	    }
	
        // Print the answer to standard output(screen).
        
		printf("Case #%d\n", test_case+1);
        printf("%c\n", Answer);     //문자열 출력으로 변경
        
	}

	return 0;//Your program should return 0 on normal termination.
}