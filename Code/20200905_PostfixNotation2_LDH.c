#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//BAEKJOON 1935, 200911 Postfix Notation2 후위표현식2(Stack), LDH

typedef struct Stack
{
	int top;
	double data[100];
}Stack;

//stack push
void push(Stack *s, double d)
{
	s->top += 1;
	s->data[s->top] = d;
}

//stack pop
double pop(Stack *s)
{
	double temp = s->data[s->top];	
	s->top -= 1;
	
	return temp;
}

//stack 현재 위치 반환
double peek(Stack *s)
{
	return s->data[s->top];
}

void calculate(Stack *s, char ch, double x, double y)
{
    switch(ch)
	{
        case '+':
            push(s, x+y);
            break;
        case '-':
            push(s, x-y);
            break;
        case '*':
            push(s, x*y);
            break;
        case '/':
            push(s, x/y);
            break;
    }
}

int main(int argc, char* argv[], char* env[])
{
    Stack s;
    s.top = -1;		//stack 초기화
    char str[100] = {0,};
    int i = 0;
    int num = 0;
    
    scanf("%d", &num);
    
	double array[num] = {0,};

    scanf("%s", str);

    for(i = 0; i < num; i++)
	{
        scanf("%lf", &array[i]);
    }

    for(i = 0; i < strlen(str); i++)
	{
        char ch = str[i];
        switch(ch)
		{
			//연사자인 경우 앞에 두개 숫자 pop해서 연산
            case '+': case '-': case '*': case '/':
                calculate(&s, ch, pop(&s), pop(&s));
                break;
			//알파벳일 경우 stack에 push
            default:
                push(&s, array[ch-('A')]);
                break;
        }
    }
    
	printf("%.2lf", peek(&s));	//소수점 2자리까지 출력
	
    return 0;
}