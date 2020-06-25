#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());

    int paper_num = citations.size();
    int temp = citations.back();
    int index = citations.size() - 1;
    
    while(index >= 0)
    {
        if((index > 0) && citations[index-1] >= temp)
        {
            index--;
        }
        
        if((paper_num - index) >= temp)
        {
            answer = temp;
            break;
        }
        else
        {
            temp--;
        }
    }
    
    return answer;
}
