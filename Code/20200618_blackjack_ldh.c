#include<stdio.h>
#include<stdlib.h>

//LDH, 200623
//Blackjack

int calcBlackjack(int *cardNum, int blackjackNum, int card);

int main(int argc, char *argv[], char *env[])
{
	int card = 0;
	int blackjackNum = 0;
	int cardNum[100] = {0,};
	int result = 0;

	scanf("%d", &card);
	scanf("%d", & blackjackNum);

	if(card < 3 || card > 100)
	{
		fprintf(stderr, "Wrong the Number of Card\n");
		exit(EXIT_FAILURE);
	}

	if(blackjackNum < 10 || blackjackNum > 300000)
	{
		fprintf(stderr, "Wrong Blackjack Number\n");
		exit(EXIT_FAILURE);
	}

	//printf("card %d\nblackjackNum %d\n", card, blackjackNum);
	
	for(int i = 0; i < card; i++)
	{
		scanf("%d", &cardNum[i]);
		if(cardNum[i] > 100000)
		{
			fprintf(stderr, "Card Number is Too Big!\n");
			exit(EXIT_FAILURE);
		}
		//printf("cardNum[%d] : %d\n", i, cardNum[i]);
	}

	result = calcBlackjack(cardNum, blackjackNum, card);

	printf("%d\n", result);

	return 0;
}

int calcBlackjack(int *cardNum, int blackjackNum, int card)
{
	int result = 0;
	int value = 0;

	for(int i = 0; i < card; i++)
	{
		for(int j = i + 1; j < card; j++)
		{
			for(int k = j + 1; k < card; k++)
			{
				value = cardNum[i] + cardNum[j] + cardNum[k];
				if(value <= blackjackNum && value > result)
				{
					result = value;
				}
			}
		}
	}

	return result;
}
