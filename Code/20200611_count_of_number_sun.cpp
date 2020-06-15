#include <iostream>

using namespace std;

int counter(int A, int B, int C);

int main(int argc, char* argv[], char* env[])
{
	int A, B, C;

	cin>>A>>B>>C;

	counter(A, B, C);

	return 0;
}

int counter(int A, int B, int C)
{
	int num_counter[10] = {0,};
	int product = A * B * C;
	int bit;

	while(product)
	{
		bit = product % 10;
		product /= 10;
		num_counter[bit]++;
	}

	for(int i=0; i<10; i++)
	{
		cout<<num_counter[i]<<endl;
	}

	return 0;
}
