## 트리

--------------------------

계층 관계를 갖는 객체를 표현하기 위해 만든 자료구조 

탐색형 자료 구조로 유용하게 쓰임

 </br>

#### 트리의 활용 예시 

계층을 표현하는 트리의 개념

이진 검색 트리 

우선순위 큐

문자열을 표현하는 트리 트라이 

</br>

### 트리의 구성 요소

- 부모 

- 자식

- 루트 노드
- 가지 노드
- 잎 노드 (leaf)
- 노드의 깊이(depth) : 루트 노드에서 해당 노드 까지의 길이 (간선의 수)
- 레벨 : 깊이가 같은 노드의 집합
- 트리의 높이(height) : 가장 깊은 노드의 깊이 
- 포화 이진 트리 : 모든 잎의 레벨이 동일한 이진 트리 (모든 노드가 2개의 자식을 가짐)
- 완전 이진 트리 : 왼쪽부터 빈 노드 없이 채워진 이진 트리 

</br>

#### 트리의 재귀적 속성

트리에서 한 노드와 그의 자손들을 모으면 그들도 하나의 트리가 된다. 

t를 루트로 하는 **서브트리(subtree)** : 어떤 노드 t와 그 자손들(descendant) 로 구성된 트리

* 자손들: 자식 노드와 그의 자식들 전부. 

</br>

--------------------------------

### 트리의 구현 

1. 부모와 자식들을 가리키는 포인터로 구현

힙의 경우, 완전이진트리 (가능한 왼쪽부터 노드를 완전히 채움)이므로 배열을 사용해 표현 가능

```c++
typedef struct TreeNode{
	int data; // 저장할 자료 
    TreeNode* parent; // 부모 노드를 가리키는 포인터
    vector<TreeNode*> child; // 자손 노드를 가리키는 포인터배열
}TreeNode;
```

 </br>

2. left child- right sibling 표현법

   이진검색트리에서는 왼쪽 오른쪽 자식 하나씩만 가질 수 있으니까 포인터 2개를 이용

```c++
typedef struct Node{
	int data;
	struct Node* leftChild;  // 왼쪽 자식
    struct Node* rightSibling; // 오른쪽 자식
}Node;
```

 </br>

### 자식 노드 연결 

부모 노드와 자식 노드 포인터를 입력 받는다.

자식이 없다면, 바로 연결한다. 

자식이 있다면, rightSibling 포인터를 이용하여 마지막 자식을 찾아내서 새 자식(?)을 연결한다.

```c++
/* 부모에게 자식 연결 */ 
void ConnectChild(Node** parent, Node* child) { 
    if (NULL == (*parent)->leftChild) { // 자식이 없다면, 
        (*parent)->leftChild = child; 
        
    } else { // 자식이 있다면, 끝을 찾아서 연결한다. 
        Node* lastChild = (*parent)->leftChild; 
        
        while (NULL != lastChild->rightSibling) { // 오른쪽 자식이 있다면, 그 옆으로 가본다.
            lastChild = lastChild->rightSibling; 
        } 
        
        lastChild->rightSibling = child; 
    } 
}
```

 </br>

### 트리의 순회 

트리의 재귀적 특성을 이용한다. 

```c++
// depth를 구분하여 노드를 순회하며 출력하는 함수

void Print(Node* node, int depth) { 
	int num = 0; // 깊이 만큼 들여쓰기 
    
    for (num = 0; num < depth; num++) { 
        printf(" "); 
    } 
    // 데이터 출력 
    printf("%d\n", node->data); 
    
    // depth를 더해서 자식노드를 출력하도록 함수 재귀 호출 (자식이니까 depth 증가)
    if (NULL != node->leftChild) { 
        Print(node->leftChild, depth++); 
    } 
    // 형제노드를 출력하도록 함수 재귀 호출 (형제는 depth 유지) 
    if (NULL != node->rightSibling) { 
        Print(node->rightSibling, depth); 
    } 
}
```

</br>

------------------------------------

## 이진 트리의 순회

 왼쪽에서 오른쪽으로 순회하는 것은 같다. 

'루트 노드'를 언제 방문하는지를 기준으로 3가지 순회 방식이 있다. 

* 전위 순회 : **루트**, 왼쪽 서브트리, 오른쪽 서브트리 
* 중위 순회 : 왼쪽 서브트리, **루트**, 오른쪽 서브트리
* 후위 순회: 왼쪽 서브트리, 오른쪽 서브트리, **루트**

</br>

```c++
/* 전위 순회 */ 

void Preorder(Node* node) { 
	// 루트 -> 왼쪽 -> 오른쪽 
	if (NULL == node) { 
        return; 
    } 
    
    printf("%d\n", node->data); // 가장 먼저 출력 
    
    Preorder(node->leftChild); // 왼쪽
    
    Preorder(node->rightSibling); // 오른쪽

}
```

</br>

```c++
/* 중위 순회 */ 

void Inorder(Node* node) { 
	// 왼쪽 -> 루트 -> 오른쪽 
	if (NULL == node) { 
        return; 
    } 
    
    Inorder(node->leftChild); // 왼쪽으로 먼저 가본다 
    
    printf("%d\n", node->data); 
     
    Inorder(node->rightSibling); // 오른쪽
}
```

</br>

```c++
/* 후위 순회 */ 

void Postorder(Node* node) { 
	// 왼쪽 -> 오른쪽 -> 루트
    
	if (NULL == node) { 
        return; 
    } 
    
    Postorder(node->leftChild); // 왼쪽
    
    Postorder(node->rightSibling); // 오른쪽
    
    printf("%d\n", node->data); 
}
```



</br>

-------------------------------------

## 문제 : 트리 순회 순서 변경하기 

어떤 이진 트리를 전위 순회했을 때 노드들의 방문 순서와, 중위 순회했을 때 노드들의 방문 순서가 주어진다. 

이 트리를 후위 순회 했을 때 각 노드들을 어떤 순서대로 방문하게 될 지 계산하는 프로그램을 작성하세요.

시간 및 메모리 제한 : 1초, 64MB 이하의 메모리

**전위** 순회하면 모든 노드를 **27**, 16, 9, 12, 54, 36, 72의 순서대로 방문

**중위** 순회했을 때는 9, 12, 16, **27**, 36, 54, 72의 순서로 방문

**후위** 순회했을 때는 12, 9, 16, 36, 72, 54, **27**의 순서로 방문

[트리 순회 순서 변경 문제링크] (https://algospot.com/judge/problem/read/TRAVERSAL)

</br></br>

#### 풀이 포인트

전위 순회(preorder)의 시작은 root (preorder[0])

중위 순회(inorder)의 값이 root와 일치하기 전 까지가 왼쪽 서브트리의 원소들이다.

그 이후에 방문한 원소들은 오른쪽 서브트리의 원소들이다.

전위 순회로 서브트리 마다의 루트를 찾고, 중위 순회에서 루트를 기준으로 왼쪽 자식의 개수를 구할 수 있다.

이를 이용해 왼쪽과 오른쪽 자식을 잘라 탐색 한다. 

**preorder[]와 inorder[]를 적절히 잘라 왼쪽 서브트리의 방문 순서, 오른쪽 서브트리의 방문 순서로 나누기**

</br>

#### 코드 

```c++
#include <vector>
#inclue <stdio.h>
#include <algorithm>
using namespace std;

vector<int> slice(const vector<int>& v, int from, int to){
    return vector<int>(v.begin() + from, v.begin() + to);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder ){
    
    // 트리에 포함된 노드 수 
    const int N = preorder.size();
    // 기저사례 : 빈 트리면 종료
    if(preorder.empty()) return;
    // preorder[0] == root 
    const int root = preorder[0];
    
    // 이 트리의 왼쪽 서브트리의 크기 L : 중위 순회 에서의 루트의 위치를 찾아서 대입
    // find 함수는 포인터값을 반환하기 때문에 -inorder.begin() 즉 시작 주소를 빼줘야 위치를 알 수가 있다.
    // L == 루트의 위치
    const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    
    // 이 트리의 오른쪽 서브트리의 크기 R : N에서 왼쪽 서브트리와 루트를 뺀다 
    const int R = N -1 -L;
    
    // 왼쪽 서브트리 ( 16, 9, 12 ) ( 9, 12, 16 )
    printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
    // 오른쪽 서브트리 (루트 이후)  (54, 36, 72) ( 36, 54, 72)
    printPostOrder(slice(preorder, L+1, N), slice(inorder, L+1, N));
    
    printf("%d ", root); // 후위순회니까 루트를 가장 마지막에 출력 
}
```





