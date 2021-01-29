#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int high = *max_element(stones.begin(), stones.end());
    int low = *min_element(stones.begin(), stones.end());
    int temp = 0;
    int counter = 0;
    int i = 0;  // for loop
    
    while(low <= high)
    {
        temp = (low + high) / 2;
        
        counter = 0;
        
        for(i=0; i<stones.size(); i++)
        {
            if(stones[i] <= temp - 1)
            {
                counter++;
                
                if(counter >= k)
                {
                    break;
                }
            }
            else
            {
                counter = 0;
            }
        }
        
        if(counter >= k)
        {
            high = temp - 1;
        }
        else
        {
            low = temp + 1;
            
            answer = max(temp, answer);
        }
    }
    
    return answer;
}
