#include <stdio.h>

int Answer;

int main(void)
{
	int T, test_case;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
	    int change = 0;
	    int ten, fifty, hund, fivehund = 0;
	    
	    scanf("%d", &change);
	    
	    if(change >= 500)
	    {
	        fivehund = change / 500;
	        change %= 500;
	    }
	    
	    if(change >= 100)
	    {
	        hund = change / 100;
	        change %= 100;
	    }
	    
	    if(change >= 50)
	    {
	        fifty = change / 50;
	        change %= 50;
	    }
	    
	    if(change >= 10)
	    {
	        ten = change / 10;
	    }
	
        // Print the answer to standard output(screen).
        
		printf("Case #%d\n", test_case+1);
	    printf("%d %d %d %d\n", ten, fifty, hund, fivehund);
	}

	return 0;//Your program should return 0 on normal termination.
}
