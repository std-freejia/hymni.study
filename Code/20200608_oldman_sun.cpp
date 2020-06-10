#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

const int alph_to_num[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};  // Convert letters to numbers

int time_acc(char* phone_num); // Calculate time

int main(int argc, char* argv[], char* env[])
{
	char* phone_num = (char*)malloc(sizeof(char));

	cout<<"Input your phone number : ";
	cin>>phone_num;

	time_acc(phone_num);

	free(phone_num);
	return 0;
}

int time_acc(char* phone_num)
{
	int len = strlen(phone_num);
	int timer = 0;
	
	for(int n=0; n<len; n++)
	{
		// Check input characters
		if(phone_num[n] < 'A' || phone_num[n] > 'Z')
		{
			cout<<"Wrong number!"<<endl;
			return 0;
		}

		timer += (alph_to_num[phone_num[n]-65] + 1);
	}

	cout<<timer<<endl;
	return 0;
}
