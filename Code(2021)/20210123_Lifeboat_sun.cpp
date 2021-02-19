#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int front = 0;
    int back = people.size() - 1;

    sort(people.begin(), people.end());

    while(front <= back)
    {
        if(front == back)
        {
            answer++;
            break;
        }

        if(people[front] + people[back] <= limit)
        {
            front++;
        }

        back--;
        answer++;
    }

    return answer;
}
