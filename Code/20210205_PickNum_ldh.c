#include <stdio.h>

int Answer;

int main(void)
{
	int T, test_case;
	// freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
	
	    int N = 0;
	    int result = 0;
	    
	    scanf("%d", &N);
	    
	    //XOR연산 두번 적용시 0 -> 입력받은 전체수를 계속 XOR 연산 해주면 답 도출가능
	    for(int i = 0; i < N; i++)
	    {
	        int input = 0;
	        scanf("%d", &input);
	        
	        result = result ^ input;
	    }
	
	
        // Print the answer to standard output(screen).
        
		printf("Case #%d\n", test_case+1);
        printf("%d\n", result);     //전역변수 Answer를 이용하면 오답
        
	}

	return 0;//Your program should return 0 on normal termination.
}