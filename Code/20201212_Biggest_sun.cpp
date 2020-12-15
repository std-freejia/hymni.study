#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = 1;
    int counter = 1;

    while(k)
    {
        if(idx == number.size() || number[idx - 1] < number[idx])
        {
            number.erase(idx - counter, min(k, counter));
            k -= min(k, counter);
            idx = 1;
            counter = 1;
        }
        else if(number[idx - 1] == number[idx])
        {
            while(number[idx - 1] == number[idx])
            {
                idx++;
                counter++;
            }
        }
        else
        {
            idx++;
            counter = 1;
        }
    }

    answer = number;

    return answer;
}
