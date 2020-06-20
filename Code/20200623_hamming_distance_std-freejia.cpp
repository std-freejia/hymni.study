#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// 해밍 거리  백준 3449번.  
// by std-freejia

void Go(void){
	
	int j = 0, cnt = 0;
	string a, b;

	cin >> a >> b;

	for(j = 0; j < a.size(); j++){
		
		if(a[j] != b[j]){
			cnt++;
		}
	}
	
	printf("Hamming distance is %d.\n", cnt);

	return;	
}

int main(int argc, char** argv){

	int repeat, i = 0;

	scanf("%d", &repeat);
	
	for(i=0; i<repeat; i++){
		Go();
	}
	
	return 0;
}



