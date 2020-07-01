#include <string>
#include <vector>
#include <algorithm>

//ldh
//programmers H-Index

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int paperCount = citations.size();
    int compareCount = paperCount;

    sort(citations.begin(), citations.end());

    for(int i = 0; i < compareCount; i++)
    {
        if(paperCount <= citations[i])
        {
            answer = paperCount;
            break;
        }
        paperCount--;
    }
   
    return answer; 
}