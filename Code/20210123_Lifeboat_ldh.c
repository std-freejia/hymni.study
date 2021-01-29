#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {

	//프로그래머스, 구명보트, LDH
    int answer = 0;
    int i = 0;
    int j = people.size()-1;
    
    sort(people.begin(), people.end());    //오름차순 정렬
    
    while(i <= j)
    {
        if(people[i] + people[j] <= limit)	//people 배열의 가장 작은 수와 큰 수의 합이 limit 이하
        {
            i++;	//가장 앞에있는 사람 보트 태움
            j--;	//가장 뒤에있는 사람 보트 태움
        }
        else
        {
            j--;	//가장 뒤에있는 사람 보트 태움
        }
        
        answer++;
    }
    
    return answer;
}