#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    int first_id = -1;
    int check_id = 0;
    int len = priorities.size();
    
    vector<int> ascending_order;
    
    ascending_order.assign(priorities.begin(), priorities.end());
    
    sort(ascending_order.begin(), ascending_order.end());
    
    while(1)
    {
        check_id = (first_id + 1) % len;
        
        while(1)
        {
            if(ascending_order.back() == priorities[check_id])
            {
                ascending_order.pop_back();
                
                first_id = check_id;
                
                if(first_id == location)
                {
                    return answer;
                }
                else
                {
                    answer++;
                    
                    break;
                }
            }
            else
            {
                check_id = (check_id + 1) % len;
            }
        }
    }
}
