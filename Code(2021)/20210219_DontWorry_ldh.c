#include <stdio.h>

int Answer;

int main(void)
{
	int T, test_case;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
	    int result = 0;
	    int A, B, D = 0;
	    scanf("%d %d %d", &A, &B, &D);
	    
	    result = (D-A) / (A-B) + 1;
	    
	    if((D-A) % (A-B) > 0)
	    {
	        result++;
	    }

        // Print the answer to standard output(screen).
        
		printf("Case #%d\n", test_case+1);
        printf("%d\n", result);
	}

	return 0;//Your program should return 0 on normal termination.
}