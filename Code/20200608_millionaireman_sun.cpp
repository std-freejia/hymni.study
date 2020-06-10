#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

bool cmp(int a, int b);
int S(int N, int *A, int *B);

int main(int argc, char* argv[], char* env[])
{
	int N, n;

	cout<<"Input N : ";
	cin>>N;

	int A[N], B[N];

	n = 0;

	cout<<"Input A : ";
	while(n < N)
	{
		cin>>A[n];
		n++;
	}

	n = 0;

	cout<<"Input B : ";
	while(n < N)
	{
		cin>>B[n];
		n++;
	}	

	S(N, A ,B);

	return 0;
}

bool cmp(int a, int b)
{
	return a>b;
}

int S(int N, int *A, int *B)
{
        int sum = 0;

        sort(A, A+N);
        sort(B, B+N, cmp);

        for(int i=0; i<N; i++)
        {
                sum += (A[i] * B[i]);
        }
        cout<<sum<<endl;

        return 0;
}
