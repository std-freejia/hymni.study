#include <vector>
#include <algorithm>

using namespace std;

const int MAX_STAGE = 500;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<float, int>> rate;
    float arrived[MAX_STAGE + 1] = {0};
    float failed[MAX_STAGE + 1] = {0};
    int i = 0;  // for loop
    int j = 0;  // for loop
    int idx = -1;
    
    for(i=0; i<stages.size(); i++)
    {
        for(j=1; j<stages[i]; j++)
        {
            arrived[j]++;
        }
        
        if(j < N + 1)
        {
            failed[j]++;
            arrived[j]++;
        }
    }
    
    for(i=1; i<=N; i++)
    {
        arrived[i] == 0 ? rate.push_back(make_pair(0, i)) : rate.push_back(make_pair(failed[i] / arrived[i], i));
    }
    
    sort(rate.begin(), rate.end());
    
    for(i=0; i<N; i++)
    {
        if(i > 0 && rate[i].first > rate[i - 1].first)
        {
            answer.insert(answer.begin(), rate[i].second);
            idx = 0;
        }
        else
        {
            answer.insert(answer.begin() + idx + 1, rate[i].second);
            idx++;
        }
    }
    
    return answer;
}
