#include <stdio.h>

//ldh, deck, 백준 10866

void push_front(int a);
void push_back(int a);
int pop_front();
int pop_back();
int front();
int back();
int size();
int empty();

char input[20];		//입력받은 명령어 처리
int arr[100000];
int start = 50000;
int end = 50001;

int main(int argc, char* argv[], char* env[])
{
	int command = 0;	//명령어 개수
	
	scanf("%d", &command);

	for(int i = 0; i < command; i++)
	{
		scanf("%s", &input);
		
		//push_front
		if(input[1] == 'u' && input[5] == 'f')	//p'u'sh_'f'ront 검사
		{
			int j = 0;
			scanf("%d", &j);
			push_front(j);
		}
		//push_back
		else if(input[1] == 'u' && input[5] == 'b')	//p'u'sh_'b'ack 검사
		{
			int j = 0;
			scanf("%d", &j);
			push_back(j);
		}
		//pop_front
		else if(input[1] == 'o' && input[4] == 'f')
		{
			printf("%d\n", pop_front());
		}
		//pop_back
		else if(input[1] == 'o' && input[4] == 'b')
		{
			printf("%d\n", pop_back());
		}
		//size
		else if(input[0] == 's')
		{
			printf("%d\n", size());
		}
		//empty
		else if(input[0] == 'e')
		{
			printf("%d\n", empty());
		}
		//front
		else if(input[0] == 'f')
		{
			printf("%d\n", front());
		}
		//back
		else if(input[0] == 'b')
		{
			printf("%d\n", back());
		}
	}

	return 0;
}

void push_front(int a)
{
	arr[start--] = a;
}

void push_back(int a)
{
	arr[end++] = a;
}

int pop_front()
{
	if(arr[start+1] == 0)
	{
		return -1;
	}
	else{
		int a = arr[start+1];
		arr[++start] = 0;
		return a;
	}
}

int pop_back()
{
	if(arr[end-1] == 0)
	{
		return -1;
	}
	else
	{
		int a = arr[end-1];
		arr[--end] = 0;
		return a;
	}
}

int size()
{
	return end-start-1;
}

int empty()
{
	if(end-start-1 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int front()
{
	if(arr[start+1] == 0)
	{
		return -1;
	}
	else
	{
		return arr[start+1];
	}
}

int back()
{
	if(arr[end-1] == 0)
	{
		return -1;
	}
	else
	{
		return arr[end-1];
	}
}