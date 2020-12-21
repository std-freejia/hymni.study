#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b);

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num_s;
    int i = 0;  // for loop
    
    for(i=0; i<numbers.size(); i++)
    {
        num_s.push_back(to_string(numbers[i]));
    }
    
    sort(num_s.begin(), num_s.end(), cmp);
    
    for(i=0; i<num_s.size(); i++)
    {
        answer += num_s[i];
    }
    
    if(answer.front() == '0')
    {
        answer = "0";
    }
    
    return answer;
}

bool cmp(string a, string b)
{
    return a + b > b + a;
}
