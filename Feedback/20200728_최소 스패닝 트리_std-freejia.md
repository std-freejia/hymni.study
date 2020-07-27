## 최소 스패닝 트리 (Minimum cost spanning tree)



### 스패닝 트리 (spanning tree)

그래프에 있는 모든 정점을 포함하는 부분 그래프

**N개의 정점(vertex)와 N-1개의 간선(edge)으로 구성** 

간선들이 트리 형태이며, 간선들이 **정점들을 전부 연결**해야 한다.

> 간선이 트리 형태여야 한다?
>
> 선택된 간선들이 **사이클(cycle)을 이루지 않는다**는 의미 

연결 그래프에서 1개 이상의 스패닝 트리를 얻을 수 있다. 

![스패닝 트리](https://gmlwjd9405.github.io/images/algorithm-mst/spanning-tree.png)

 </br>

#### DFS, BFS로 얻을 수 있는 스패닝 트리

연결 그래프에서, DFS나 BFS는 암묵적으로 그래프 G의 간선(edge)을 두 개의 집합으로 분리한다. 

* T : 스패닝 트리의 edge 집합으로 사용되거나 search 도중에 방문
* N : 남아있는 edge의 집합

아래 그림에서 V(정점)는 8개, E(간선)은 7개이다. 

(만약 edge가 vertext의 개수와 같아지면 cycle이 생긴다. )

![dfs bfs spanning tree](https://t1.daumcdn.net/cfile/tistory/99099C435BAB4FC131)

(a) DFS spanning tree : **아직 방문하지 않은 정점으로 향하는 간선이 있으면 그 간선을 무조건 따라간다.**  가능한 한 그래프 안으로 '깊이' 간선을 따라가며, **막힌 정점에 도달하면 뒤로 돌아간다.** 

(b) BFS spanning tree : 각 정점을 방문할 때 마다 모든 **인접 정점**을 검사하므로 V0에서 V1과 V2 쪽으로 순차적으로 두 간선을 방문한다.  

 </br>

### 최소 스패닝 트리 (minimum cost spanning tree)

가중치 그래프의 스패닝 트리 중, 가중치의 합이 가장 작은 트리

즉, 그래프의 연결성은 유지하되 가장 '저렴한' 그래프

> 정점이 N개라면, 간선은 N-1개만을 포함한다. 
>
> 사이클을 만드는 간선은 선택하지 않는다. 

</br>

--------------------

####  최소 스패닝 트리 알고리즘 

크루스칼(Kruskal), 프림(Prim), 솔린(Sollin) 알고리즘이 대표적

이 알고리즘 모두 탐욕 알고리즘이다. 

> 탐욕 알고리즘(greedy method)
>
> 각 단계에서 어떤 기준을 두고 최선의 선택을 한다. 

 </br>

#### 1. 크루스칼

상호 배타적 집합 자료 구조의 사용 예 

**모든 간선(edge)을 가중치의 오름차순으로 정렬한다.** 

특정 노드에서 시작하는게 아니다. 

**모든 간선 중에서** 가장 작은 edge를 선택하여 스패닝 트리에 **하나씩 추가**해 간다. (간선 조각들을 하나씩 모은다.)

이 때, 추가하면 사이클이 생기는 간선을 확인하여 제외시킨다. 

</br>

#### 크루스칼 알고리즘 탐색 예시  

![image-20200727184356865](C:\Users\wtfre\AppData\Roaming\Typora\typora-user-images\image-20200727184356865.png)

> 간선 가중치를 정렬한 결과  **10, 12, 14, 16, 18, 22, 24, 25, 28**

그림 (f) 에서 (g) 를 눈여겨보자. 

(f) 10, 12, 14, 16을 추가한 트리

(g) 18을 추가하면 사이클이 발생하므로 18을 제외시키고, 22를 추가한다. 

![image-20200727184530958](C:\Users\wtfre\AppData\Roaming\Typora\typora-user-images\image-20200727184530958.png)

[크루스칼 알고리즘 그림 출처](https://brownbears.tistory.com/396)

</br>

#### 2. 프림 

다익스트라 알고리즘과 비슷

하나의 정점으로 구성된 트리에서 시작.

여기에 간선을 **하나씩 추가**하며 스패닝 트리가 될 때까지 키워 간다.

**이미 만들어진 트리에 인접한 간선만 고려**한다. 

</br>

#### 프림 알고리즘 탐색 예시 

![image-20200727184356865](C:\Users\wtfre\AppData\Roaming\Typora\typora-user-images\image-20200727184356865.png)



![image-20200727184929498](C:\Users\wtfre\AppData\Roaming\Typora\typora-user-images\image-20200727184929498.png)

[프림 알고리즘 그림 출처](https://brownbears.tistory.com/396)