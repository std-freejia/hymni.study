using namespace std;

bool solution(int x) {
    int sum = 0;
    int temp = x;
    
    while(temp)
    {
        sum += temp % 10;
        temp /= 10;
    }
    
    return !(x % sum);
}
