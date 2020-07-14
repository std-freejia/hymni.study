## 스택

가장 먼저 들어간 요소가 가장 마지막에 나오는 구조 

후입선출 FILO(First In Last Out)

함수들의 문맥(context)을 관리하는 데 활용



###  배열로 구현하는 스택

한쪽 끝에서만 자료의 추가/삭제가 일어나므로 동적 배열을 사용할 수 있다. 

head와 tail의 위치를 가리키는 변수를 활용한다. 

head는 첫번째 원소의 위치를 가리킨다

tail은 마지막 원소의 다음위치를 가리킨다. 



#### 스택의 노드

```c++
typedef struct Node { 
	int data; 
}Node;

```

#### 스택 구조체 

```c++
typedef struct ArrayStack { 
    int capacity;	 /* 배열 용량 */ 
    int top;		 /* 최상위 노드 위치 */ 
    Node* arrayNodes; /* 노드들을 보관하는 스택배열 */ 
}ArrayStack;
```



#### 삽입연산 PUSH

현재 top 위치에 데이터를 넣는다. 그리고 top 위치를 갱신한다.

```c++
void Push(ArrayStack* stack, int inputData) { 
    
    printf("[ 삽입연산 Push ] %d를 Push \n", inputData); 
    int location = stack->top; 
    
    stack->arrayNodes[location].data = inputData; 
    stack->top = location + 1; 
}
```



#### 제거연산 POP

top 에 있던 data를 호출자에게 반환한다.  top값을 1 감소 시킨다. 

```c++
int Pop(ArrayStack* stack) { 
    printf("[ 제거연산 Pop ]\n"); 
    
    int location = --(stack->top); 
    return stack->arrayNodes[location].data; 
}

```



#### 스택이 비었는지 확인 

POP 전에 스택이 비었는지 확인한다. 

비었다면 1, 요소가 있다면 0 반환 

```c++
/* 스택이 비었는지 확인 : 제거 전에 확인 */ 
int isEmpty(ArrayStack* stack) { 

    return (0 == stack->top); 
}
```



#### 스택이 꽉 찼다면? 

동적 배열기반 방법

```c++
void DoubleStack(ArrayStack* stack){
    stack->capacity *= 2; // 용량 2배
    stack->arrayNodes = realloc(stack->arrayNodes, stack->capacity); // 재할당 
}
```





---------------------------------------



## 큐 

한쪽 끝에서 자료를 넣고 반대 쪽 끝에서 자료를 꺼내는 구조 

선입선출

전단에서 제거(Dequeue)되고 후단에서 삽입(Enqueue)한다.



### 배열로 구현한 순환큐

시작과 끝을 연결하도록 고안된 큐 

특징 :**큐가 비었는지 가득찼는지 구분하기 위해 큐를 실제 용량보다 1 크게 만든다**

큐를 생성할 때  **Node의 크기 X (Capacity + 1)** 의 크기로 배열을 할당받는다. 

큐가 공백/포화 인지 구분할 더미노드가 필요하기 때문이다.

전단은 첫번째 요소의 위치를 가리킨다.

후단은 마지막 요소의 '다음'위치를 가리킨다.



##### 큐가 비어있다면?

전단과 후단이 같은 곳을 가리킨다.

##### 큐가 꽉찼다면?

후단은 마지막 요소의 다음 위치를 가리킨다. 

큐가 꽉 찼다면, 후단 위치의 다음 인덱스가 전단의 위치다. 

즉, 마지막 요소, 후단 위치, 전단위치 순이 된다. 



### 순환 큐의 노드와 큐 구조체

```c++
typedef struct Node { 
    int data; 
}Node; 
typedef struct Cqueue { 
    int capacity; 
    int front; 
    int rear; 
    Node* nodeArray; 
}Cqueue;
```



#### 삽입 Enqueue

뒤에서 삽입하니까 rear를 관리한다. 

rear는 '삽입할' 타겟 인덱스를 알고있다. (빈 공간을 가리킨다)

```c++
void Enqueue(Cqueue* cqueue, int data) { 
    
    int position = 0; 
    if (cqueue->capacity + 1 == cqueue->rear) { 
        // capacity + 1 인덱스는 공백/포화를 구분하는 '더미노드 위치' 
        position = cqueue->rear; 
        cqueue->rear = 0; 
    } else { 
        position = cqueue->rear++; 
    } 
    cqueue->nodeArray[position].data = data; 
}
```



#### 제거 Dequeue

앞에서 제거하니까 front를 관리한다. 

front와 capacity가 같은 상황은 전단이 배열 맨 끝에 와있다는 것.

노드를 하나 제거 하면, 인덱스를 0으로 돌려놔야 한다.

이 경우를 제외하면 front를 하나 감소시키면 된다. 

```c++
int Dequeue(Cqueue* cqueue) { 
    int position = cqueue->front; 
    if (cqueue->front == cqueue->capacity ) { 
        cqueue->front = 0; 
    }else{ 
        cqueue->front++; 
    } 
    return cqueue->nodeArray[position].data; 
}
```



#### 큐의 공백 

비어있다면 front와 rear가 같은 곳을 가리킨다.

```c++
int IsEmpty(Cqueue* cqueue) { 
    return (cqueue->front == cqueue->rear); 
}
```



#### 큐의 포화 

포화라면 rear에서 front를 빼면 그 길이가 capacity가 된다.

또는 rear의 바로 다음이 front 인지 확인한다. 

```c++
int IsFull(Cqueue* cqueue) { 
    if (cqueue->front < cqueue->rear) { 
        return (cqueue->rear - cqueue->front == cqueue->capacity); 
    } else { 
        return (cqueue->front == cqueue->rear + 1); 
    } 
}
```





