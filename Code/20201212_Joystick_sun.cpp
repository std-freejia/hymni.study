#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int id = 0;
    int next_id = 0;
    int prior_id = 0;
    int counter = 0;
    int size = name.size();
    string init(size, 'A');

    while(1)
    {
        answer += min(name[id] - 'A', 'Z' - name[id] + 1);
        init[id] = name[id];

        if(init == name)
        {
            break;
        }

        for(counter=1; counter<=size/2; counter++)
        {
            next_id = (id + counter) % size;
            prior_id = (id - counter + size) % size;

            if(init[next_id] != name[next_id])
            {
                id = next_id;
                answer += counter;
                break;
            }

            if(init[prior_id] != name[prior_id])
            {
                id = prior_id;
                answer += counter;
                break;
            }
        }
    }

    return answer;
}
