#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    int start = 0;
    int r = 0;
    int c = 0;
    int num = 2;
    vector<int> answer(n * (n + 1) / 2, 0);
    
    answer[0] = 1;
    
    while(start < n / 2)
    {
        // top -> bottom
        for(r=start+1; r<n-start; r++)
        {
            if(answer[r*(r+1)/2+start])
            {
                continue;
            }
            
            answer[r*(r+1)/2+start] = num;
            num++;
        }
        
        r--;
        
        // left -> right
        for(c=start+1; c<=r; c++)
        {
            if(answer[r*(r+1)/2+c])
            {
                break;
            }
            
            answer[r*(r+1)/2+c] = num;
            num++;
        }
        
        c--;
        
        // bottom -> top
        do
        {
            c--;
            r--;
            
            if(answer[r*(r+1)/2+c])
            {
                break;
            }
            
            answer[r*(r+1)/2+c] = num;
            num++;
        }while(c > start);
        
        start++;
    }
    
    return answer;
}
