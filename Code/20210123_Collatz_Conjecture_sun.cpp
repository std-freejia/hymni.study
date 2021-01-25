using namespace std;

int solution(int num) {
    int answer = 0;
    long long temp = num;
    
    while(temp != 1)
    {
        if(answer >= 500)
        {
            answer = -1;
            break;
        }
        
        temp = temp & 1 ? (temp * 3 + 1) : (temp / 2);
        
        answer++;
    }
    
    return answer;
}
