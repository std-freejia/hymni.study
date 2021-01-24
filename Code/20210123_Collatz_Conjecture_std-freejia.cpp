#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 콜라츠 추측 

int solution(int num) {
    
    int cnt = 500;
    long long temp = num;
    
    if(num == 1) return 0;
    
    while(temp != 1){ // 1이 될 때 까지 시도 
      
        if(cnt < 0) break; // 500번 이하 시도 
        
		if(temp % 2 == 0){
    		temp /= 2;
    		
		}else{
			temp = (temp * 3) + 1;
		}
		cnt--;
	}

    
    return (temp != 1) ? -1 : (500-cnt);

}