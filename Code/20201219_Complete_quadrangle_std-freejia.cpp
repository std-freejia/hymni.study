#include <iostream>
using namespace std;


long long gcd(long long a, long long b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

long long solution(int w,int h) {
    long long answer = 1;
	long long total = (long long)w*h;
		
    long long gcd_num = gcd((long long)w, (long long)h); // GCD

    long long temp_w = (long long)w / gcd_num;
    long long temp_h = (long long)h / gcd_num;
    
    long long block_cnt = w / temp_w;
    answer = total - (block_cnt * (temp_w + temp_h -1) );

    return answer;
}