#include <string>
#include <vector>

//ldh
//programmers Printer Priorites

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int printCount = priorities.size();
    int tmp = 0;
	
    //printf("test : %d\n",priorities.size());
    
	while(true)
	{
		for(int idx = tmp; idx < priorities.size(); idx++)
		{
			if(priorities[tmp] < priorities[idx])
			{
				priorities.push_back(priorities[tmp]);
                if(tmp == location)
                {
                    location = priorities.size() - 1;
                }
                answer--;   //출력이 안된 경우
				break;				
			}
		}
        
        if(tmp == location)
        {
            answer++;   //location에 위치한 값 출력하고 종료
            break;
        }
        tmp++;
        answer++;
	}

    return answer;
}