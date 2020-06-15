#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

const int row = 5;
const int col = 15;

int output(char(* word)[col]);

int main(int argc, char* argv[], char* env[])
{
	char(* word)[col] = (char(*)[col])malloc(row * col * sizeof(char));
	memset(word, 0, row * col * sizeof(char));  // Initialization
	
	for(int i=0; i<row; i++)
	{
		cin>>word[i];
	}

	output(word);

	free(word);
	return 0;
}

int output(char(* word)[col])
{
	for(int c=0; c<col; c++)
	{
		for(int r=0; r<row; r++)
		{
			cout<<word[r][c];
		}
	}

	cout<<endl;

	return 0;
}
