/*
1. In a set, the value of each element must be unique.
2. The elements in a set are always sorted.
*/

#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> sum;
    int i = 0;  // for loop
    int j = 0;  // for loop
    int size = numbers.size();

    // 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 set에 저장
    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            sum.insert(numbers[i] + numbers[j]);
        }
    }

    answer.assign(sum.begin(), sum.end());
    
    return answer;
}
