#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<int> idx_stack;
    int idx = 0;
    int i = 0;  // for loop

    while(idx < prices.size())
    {
        for(i=0; i<idx_stack.size(); i++)
        {
            answer[idx_stack[i]]++;
        }

       while(!idx_stack.empty() && prices[idx_stack.back()] > prices[idx])
        {
            idx_stack.pop_back();
        }

        idx_stack.push_back(idx);
        answer.push_back(0);

        idx++;
    }

    return answer;
}
