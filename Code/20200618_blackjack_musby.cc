#include <stdio.h>
#include <stdlib.h>

#define MIN_CARD_CNT		3
#define MAX_CARD_CNT		100
#define MIN_BLACKJACK_NUM	10
#define MAX_BLACKJACK_NUM	300000
#define LIMIT_CARD_NUM		100000

#define MAX_
#define MALLOC(ptr, space)	\
		if(!((ptr) = (int*)malloc(space))){		\
			fprintf(stderr, "Insufficient Memory");	\
			exit(EXIT_FAILURE);						\
		}

bool BoundaryException(int*, int*, int**);
void NearBlackjackNumber(int*, int, int);

int main(int argc, char* argv[])
{
	int blackJackNumber = 0;
	int cardCount = 0;
	int* cardNumber = NULL;
	int idx = 0;
	
	if(!(BoundaryException(&cardCount, &blackJackNumber, &cardNumber))){
		fprintf(stderr, "Out of Boundary cardCount or blackJackNumber!");	
		exit(EXIT_FAILURE);						
	}
	
	NearBlackjackNumber(cardNumber, cardCount, blackJackNumber);
	
	free(cardNumber);
	
	return 0;
}

void NearBlackjackNumber(int* cardNumber, int cardCount, int blackJackNumber)
{
	int nearBlackJack = 0;
	int idx = 0, idy = 0, idz = 0;
	
	for(idx=0; idx<cardCount-2; idx++){
		
		for(idy=idx+1; idy<cardCount-1; idy++){
			
			for(idz=idy+1; idz<cardCount; idz++){
				
				int sum = cardNumber[idx] + cardNumber[idy] + cardNumber[idz];
				
				if(nearBlackJack <= sum && sum <= blackJackNumber){
					nearBlackJack = sum;
				}
			}
		}
	}
	
	printf("%d\n", nearBlackJack);
}

bool BoundaryException(int* cardCount, int* blackJackNumber, int** cardNumber)
{
	int idx = 0;
	
	scanf("%d %d", cardCount, blackJackNumber), getchar();
	
	if(*cardCount < MIN_CARD_CNT || MAX_CARD_CNT < *cardCount){
		
		return false;
		
	}else if(*blackJackNumber < MIN_BLACKJACK_NUM || MAX_BLACKJACK_NUM < *blackJackNumber){
		
		return false;
		
	}
	
	MALLOC(*cardNumber, MAX_CARD_CNT);
	
	for(idx=0; idx<*cardCount; idx++){
		
		scanf("%d", &(*cardNumber)[idx]);
		
		if(LIMIT_CARD_NUM < (*cardNumber)[idx]){
			return false;
		}
		
	}
	
	return true;
}