using namespace std;

int GCD(int a, int b);

long long solution(int w,int h) {
    long long answer = 1;
    int counter = GCD(w, h);
    
    answer = (long long)w * (long long)h - w - h + counter;
    
    return answer;
}

int GCD(int a, int b)
{
    if(a % b == 0)
    {
        return b;
    }
    else
    {
        return GCD(b, a % b);

    }
}
