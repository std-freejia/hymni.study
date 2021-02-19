#include <stdio.h>

int Answer;

int main(void)
{
	int T, test_case;
	int scores[100] = {0, };
	
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		int result = 0;
	    int N, K, point = 0;
        
        for(int i = 0; i <= 100; i++)
        {
            scores[i] = 0;
        }
        
        scanf("%d%d", &N, &K);
        
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &point);
            scores[point]++;
        }
        
        for(int i = 100; i >= 0; i--)
        {
            if(scores[i] >= K)
            {
            	result += K * i;
                break;
            }
            else
            {
                result += scores[i] * i;
                K -= scores[i];
            }
        }
        
		printf("Case #%d\n", test_case+1);
        printf("%d\n", result);
        
	}

	return 0;//Your program should return 0 on normal termination.
}
