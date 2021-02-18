#include <stdio.h>

//Time Limit Exceed, 100점

int Answer;

int main(void)
{
	int T, test_case;
	
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
	    int N, count = 0;
	    scanf("%d", &N);
	    
	    while(N)
	    {
	        count += N % 2;
	        N /= 2;
	    }
	
		printf("Case #%d\n", test_case+1);
	    printf("%d\n", count);
        
	}

	return 0;//Your program should return 0 on normal termination.
}