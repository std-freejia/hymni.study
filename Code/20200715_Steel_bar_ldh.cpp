#include <vector>
#include <stack>
#include <string>
 
using namespace std;
 
int solution(string arrangement)
{
    int answer = 0;
    stack<int> num;
	
    //글자의 처음부터 마지막까지 순회
    for(int i = 0; i < arrangement.length(); i++)
	{
        //여는 괄호라면 스택에 추가
        if (arrangement[i] == '(')
		{
            num.push(1);
		}
        else
		{
            //닫는 괄호라면 스택에서 하나제거
            num.pop();
            //전 기호가 여는 기호였다면 레이저이므로 열린괄호만큼 개수추가
            if(arrangement[i - 1] == '(')
			{
                answer += num.size();
			}
            else//전 기호가 여는 기호가 아니었다면 쇠막대기의 마지막이므로 1개 추가
			{
                answer++;
			}
        }
    }
	
    return answer;
}