#include <iostream>
#include <algorithm>

using namespace std;

int sum_cal(int N, int M, int* cards);

int main(int argc, char* argv[], char* env[])
{
    int N=0, M=0;
    
    cin>>N>>M;
    
    int cards[N] = {0,};
    
    for(int n=0; n<N; n++)
    {
        cin>>cards[n];
    }
    
    cout<<sum_cal(N, M, cards);
    
    return 0;
}

int sum_cal(int N, int M, int* cards)
{
    int card_1, card_2, card_3;
    int optimal_sum=0, current_sum=0;
    
    // sort cards in ascending order
    sort(cards, cards+N);
    
    for(card_3=N-1; card_3>1; card_3--)
    {
        for(card_1=0; card_1<card_3-1; card_1++)
        {
            card_2 = card_1 + 1;
            
            while(card_2 < card_3)
            {
                current_sum = cards[card_1]+cards[card_2]+cards[card_3];
                
                if(current_sum > M)
                {
                    break;
                }
                
                if(current_sum > optimal_sum)
                {
                    optimal_sum = current_sum;
                }
                
                if(optimal_sum == M)
                {
                    return optimal_sum;
                }
                
                card_2++;
            }
            
            if(card_2-card_1 < 3 && current_sum > M)
            {
                break;
            }
        }
    }

    return optimal_sum;
}
