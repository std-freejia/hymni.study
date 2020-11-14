### N과 M문제집

[1부터 12까지 시리즈가 있는 N과 M 문제집](https://www.acmicpc.net/workbook/view/2052)

순열, 조합을 연습하는 N과 M 시리즈 문제다. 백준님께서 1~4번 문제가 매우 중요하다고 하셨다. 

</br>

### 문제

[N과M(1) 백준 15649번](https://www.acmicpc.net/problem/15649)

</br>

### 리뷰

재귀 호출을 이용해서 N개중에 M개를 고른다. 

M개를 고를 때, permu() 함수는 매개변수로 지금 '몇 번째' 숫자를 고른다는 기준을 잡는다. 

int check[ ] 배열을 이용해 특정 숫자를 골랐는지/안골랐는지 표시한다. 

숫자 중복을 허용하지 않기 때문에 선택 여부 표시를 위해 필요하다.  

</br>

### 코드

```c++
#include <iostream>
using namespace std;
 
int N, M;
int check[10]; // 확인 여부  
int answer[10]; // 선택한 인덱스  

void permu(int idx){ // 'idx' 번째에 어떤 수를 놓을지 고른다. 

	if(idx > M){ // 이미 M개를 골랐으니까, M번째를 초과하는 순간 종료. 
	
		// 수열 출력 
		for(int p = 1; p <= M; p++){
			cout << answer[p] << ' ';
		}
		cout << '\n';
		
		return; 
	}
	
	for(int i = 1; i <= N; i++){ 
	
		if(check[i]) continue; // 이미 선택된 수는 지나간다 
		
		check[i] = 1; // 선택 함
		answer[idx] = i; // idx 자리에 숫자 i 배치 
		
		permu(idx+1); // 다음 자리의 숫자 고르러 재귀 		 
		
		check[i] = 0; // 선택 안함  
	}
}

int main(void){

	freopen("input.txt", "rt", stdin);

	cin >> N >> M;
	
	permu(1);
	
	return 0;	
}
```

<br/>



### 문제 

[N과M(2) 백준 15650번](https://www.acmicpc.net/problem/15650)

**백준님이 강조하셨다 중요하다고.** 

</br>

### 리뷰

**오름차순** 수열을 출력하되, **숫자가 중복되지 않도록 한다.** 

즉, 이미 고른 숫자보다 큰 숫자부터 골라야 한다. 



### 코드 1

```c++
#include <iostream>
#include <algorithm> 
using namespace std;

// N과 M (2)  

int N, M;
bool check[10];
int answer[10];

void go(int index, int start){

	if(index == M){
		// 수열 출력 
		for(int i = 0; i < M; i++){
			cout << answer[i] << ' ';
		} 
		cout << '\n';
		return;
	}
	
	for(int i = start; i <= N; i++){
		if(check[i]) continue; // 이미 선택된 숫자라면 지나간다. 
		
		check[i] = true;
		answer[index] = i; // index 자리에 i를 선택한다. 
		go(index+1, i+1); // index+1 자리에 (==다음 자리)숫자를 고르기 위해 재귀 호출.
		check[i] = false; 
	}

}
 
int main(void){

 	scanf("%d %d", &N, &M);
 
	go(0, 1); // 0번째를 채우자.  
	 
	return 0;
} 
```

</br>

### 코드2 

선택 한다/ 안한다의 관점 

함수 시그니처는 아래와 같다. 

```c++
void go(int num, int selected_cnt);

// num 에는 1부터 n까지의 숫자가 들어온다.  1, 2, 3, ... n 
// selected_cnt는 0부터 m-1까지 숫자가 들어온다. 
```

1부터 n까지 수가 들어오는데, 이 숫자를 선택 할지, 말지를 선택한다. 

selected_cnt 가 m이 되는 순간 수열을 출력한다. 

선택 한다면, selected_cnt 자리에 num을 넣는다. 

```c++
arr[selected_cnt] = num; // 선택함  
go(num+1, selected_cnt+1);

arr[selected_cnt] = 0; // 선택 안함  
go(num+1, selected_cnt);
```



</br>

```c++
#include <iostream>
using namespace std;
 
// n과 m (2)

int n, m;
int arr[10]; // num 숫자를 선택 한다/안한다를 표시  

// num 에는 1부터 n까지의 숫자가 들어온다. 
// selected_cnt는 0부터 m-1까지 숫자가 들어온다. 
 
void go(int num, int selected_cnt){ // num 숫자를 선택 한다/안한다 ,  선택한 수의 개수 

	if(selected_cnt == m){
		// 수열 출력
		for(int i = 0; i < m; i++){
			printf("%d ", arr[i]);
		}
		cout << '\n';
		
		return; 
	} 
	
	if(num > n) return; // n을 초과하면 리턴  
	
	arr[selected_cnt] = num; // 선택함  
	go(num+1, selected_cnt+1);
	
	arr[selected_cnt] = 0; // 선택 안함  
	go(num+1, selected_cnt);

}

int main(void){
 
   	scanf("%d %d", &n, &m);
  	
  	go(1, 0); 
  	
	return 0;
} 
```

</br>



### 문제 

[N과M(3) 백준 15651번](https://www.acmicpc.net/problem/15651)

</br>

### 리뷰

**오름차순** 수열을 출력하되, **숫자 중복을 허용한다. ** 



### 코드 

```c++
#include <iostream>
#include <algorithm> 
using namespace std;
 
/*  n과m (3)
중복 허용
1부터 n까지 자연수 중에서 m개를 고른 수열  
*/ 

int n, m;
int arr[10]; // 출력할 수열을 담는다.  
 
void go(int index){  // index 0부터 m-1 까지 어떤 수로 채울지 선택하는 함수  

	if(index == m){ // index m-1까지 모든 수를 골랐으니까 수열 출력 
		
		for(int i = 0; i < m; i++){ // 수열 출력
			printf("%d ", arr[i]);
		}
		cout << '\n';		
		return; 
	} 
	
	for(int i = 1; i <= n; i++){ // 1부터 n까지 수를 '중복 허용'하여 선택
		arr[index] = i;
		go(index+1); // 다음 자리 숫자를 고르러 재귀호출 
	}

}

int main(void){
 
   	scanf("%d %d", &n, &m);
  	
  	go(0); // 0번째 자리에 어떤 수를 넣을지 선택한다.  
  	
	return 0;
} 
```

</br>



### 문제 

[N과M(4) 백준 15652번](https://www.acmicpc.net/problem/15652)

</br>

### 리뷰

**비내림차순** 수열을 출력하되, **숫자 중복을 허용한다. **

비내림차순은 '같은 숫자가 연속되거나 오름차순'이다. 예를 들어, 11223 같은 수열이 비내림차순이다.  

중복 허용이니까 중복체크할 배열이 필요 없다. 

</br>

### 코드 1

```c++
#include <iostream>
using namespace std;


/*   n과m (4)
중복 허용, 비내림차순  
1부터 n까지 자연수 중에서 m개를 고른 수열  
*/ 

int n, m;
int arr[10]; // 출력할 수열을 담는다.  
 
void go(int index, int start_num){  

	if(index == m){ // 수열 출력
		for(int i = 0; i < m; i++){
			printf("%d ", arr[i]);
		}
		cout << '\n';
		return; 
	} 
	
	for(int i = start_num; i <= n; i++){ // 선택 범위의 시작 숫자만 정해준다. 
		arr[index] = i; 
		go(index+1, i); // 반드시 i 보다 큰 수부터 다시 선택해야 하는게 아니다.(비내림차순)
	}

}

int main(void){
 
   	scanf("%d %d", &n, &m);
  	
  	go(0, 1); // 0번째 자리에 어떤 수를 넣을지 선택한다.  start는 선택범위의 시작숫자. 
  	
	return 0;
} 
```

</br>

### 코드 2 

m 개로 이루어진 배열 arr를 채우는 '완전탐색'  DFS로 풀이했다. 



```c++
#include <iostream>
using namespace std;
 
/*  n과m (4)  DFS로 푼 코드 
중복 허용, 비내림차순  
1부터 n까지 자연수 중에서 m개를 고른 수열  
*/ 

int n, m;
int arr[10]; // 숫자 m개를 골라 저장할 수열  
 
void dfs(int start_num, int cnt){ // 비내림차순 이니까 start_num 활용.  cnt는 선택한 숫자 개수

	if(cnt == m){ // 0 ~ m-1 까지 총 m 개 선택 완료해서 수열을 출력.
		for(int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	
	for(int i = start_num; i <= n; i++){ // 비내림차순
		arr[cnt] = i;  // cnt자리에 i숫자를 넣는다. 선택한 것.
		dfs(i, cnt+1); 
        // 비내림차순이니까 i 부터 다시 선택할 수 있게 한다. 윗줄에서 선택했으니 cnt+1을 넘긴다. 
	}
} 


int main(void){
 
  	scanf("%d %d", &n, &m);
  	
  	dfs(1, 0);  // 1부터 시작한다. 고른 개수.
	    	
	return 0;
} 
```

</br>

### 문제 

[N과M(5) 백준 15654번](https://www.acmicpc.net/problem/15654)

</br>

### 리뷰

1부터 N까지의 자연수가 아니라, 입력받은 N개의 수열을 이용한다. 

중복을 허용하지 않고 2개 고르는 것이라서 중복체크를 위해 ch [10] 배열이 필요하다. 

수열은 사전 순으로 증가하는 순으로 출력해야 하니까, 입력받자마자 sort() 했다. 

</br>

### 코드 

```c++
#include <iostream>
#include <algorithm> 
using namespace std;
 
// n과 m  (5)

int N, M; // 1부터 N까지의 자연수 중에서 M개를 고른 수열.  
int arr[10]; // 입력받은 수열 저장.
int ch[10]; // 중복을 허용하지 않으니까, 체크 배열이 필요하다.
int answer[10];

void go(int index){
	
	if(index == M){
		for(int i = 0; i < M; i++){
			printf("%d ", answer[i]);
		}
		cout << '\n';
		return;
	}
	
	for(int i = 0; i < N; i++){
		if(ch[i]) continue;
		
		ch[i] = 1;
		answer[index] = arr[i];
		go(index+1);
		ch[i] = 0;
	}
}
 
int main(void){

	cin >> N >> M;
 	
 	for(int i = 0; i < N; i++){
 		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr+N);
	
 	go(0);

	return 0;
}
```

</br>

</br>

### 문제 

[N과M(6) 백준 15655번](https://www.acmicpc.net/problem/15655)

</br>

### 리뷰

수열의 중복을 허용하지 않고, 사전 순으로 증가하는 순서로 출력해야 한다.  

수열은 오름차순이어야 하므로 go 함수에 start 변수를 넣어서 이전 인덱스 보다 큰 인덱스부터 수열의 숫자를 고르도록 했다. 

</br>

### 코드 

```c++
#include <iostream>
#include <algorithm> 
using namespace std;
 
// n과 m  (6)
// 중복 허용 안 함. 오름차순 수열.

int N, M; // 1부터 N까지의 자연수 중에서 M개를 고른 수열.  
int arr[10];
int ch[10];
int answer[10];

void go(int index, int start){
	
	if(index == M){
		for(int i = 0; i < M; i++){
			printf("%d ", answer[i]);
		}
		cout << '\n';
		return;
	}
	
	for(int i = start; i < N; i++){
		if(ch[i]) continue;
		
		ch[i] = 1;
		answer[index] = arr[i];
		go(index+1, i+1);
		ch[i] = 0;
	}
}
 
int main(void){
 
	cin >> N >> M;
 	
 	for(int i = 0; i < N; i++){
 		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr+N);
	
 	go(0, 0);

	return 0;
}
```



