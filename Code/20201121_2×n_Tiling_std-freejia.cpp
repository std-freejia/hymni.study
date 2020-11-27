#include <stdio.h>
using namespace std;

// 2xn ≈∏¿œ∏µ (BOJ 11726) 

int arr[1001]; 

int main(void){

    int n = 0;
    int i = 0;

    scanf("%d", &n);

    arr[1] = 1;
    arr[2] = 2;

    for(i = 3; i <= n; i++){

        arr[i] = (arr[i-1] + arr[i-2]) % 10007;

    }

    printf("%d", arr[n]);

    return 0;
}
