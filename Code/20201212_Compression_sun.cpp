#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
    int size = s.size();
    int answer = size;
    int counter = 1;
    int total = 0;
    int i = 0;  // for loop
    int j = 0;  // for loop
    string sub = "";

    for(i=1; i<=size/2; i++)
    {
        sub = "";
        total = 0;
        counter = 1;

        for(j=0; j<size; j+=i)
        {
            if(sub == s.substr(j, i))
            {
                counter++;

                if((j + i) > (size - 1))
                {
                    total += to_string(counter).size();
                }
            }
            else
            {
                if(counter > 1)
                {
                    total += to_string(counter).size();
                }
                sub = s.substr(j, i);
                total += sub.size();
                counter = 1;
            }
        }

        answer = min(answer, total);
    }

    return answer;
}
