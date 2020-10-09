## 다양한 그래프 알고리즘
이번에는 `DisjointSet`, `크루스칼 알고리즘`, `위상 정렬`에 대해서 알아보자.

### DisjointSet (서로소 집합)
`공통 원소가 없는 두 집합`을 서로소 집합 관계라고 한다.    
가장 중요한 연산은 2가지이다.    
1. `union` 2개의 원소가 포함된 집합을 하나의 집합으로 합치는 연산
2. `find` 특정한 원소가 속한 집합이 어떤 집합인지 알려주는 연산    

`union-find 자료구조`라고도 한다.
* 부모 노드를 가리키는 배열이 필요하다.   
  + 이 배열은 해당 원소의 부모 노드를 지칭하는 배열이다.    
  + ```cpp
    int parent[10]; // parent[i] = 1 이라고 하면, i 원소의 부모 노드는 1이다.
    ```
* find 연산은 아래와 같은 과정을 통해서 구현할 수 있다.
  + 해당 원소가 속한 집합이 어떤 집합인지를 알려주는 연산으로 해당 원소가 속한 집합의 루트 노드를 찾아준다.
  + 이 때, 아주 간단한 과정으로 최적화가 가능한 `경로 압축 기법`을 이용하면 더 빠르게 알고리즘이 될 수 있다.
  ```cpp
  int findParent(int x){
    if(parent[x] == x) return x; // 해당 x의 루트 노드가 x라면 루트 노드를 찾은 것이다.
    //return findParent(parent[x]); // 경로 압축 기법을 이용하지 않은 코드
    return parent[x] = findParent(parent[x]); // 경로 압축 기법을 이용한 코드
  }
  ```
* union 연산은 아래와 같은 과정을 통해서 구현할 수 있다.
  + a와 b의 루트 노드를 각각 찾는다. 이 때의 a의 루트 노드는 a', b의 루트 노드는 b'
  + a'를 b'의 부모 노드로 설정하든, b'를 a'의 부모 노드로 설정하든 상관없이 한 쪽으로 붙여준다.
  + 이 부분을 코드로 표현하면 다음과 같다.
  ```cpp
  void unionParent(int a, int b){
    a = findParent(a); // a의 루트 노드를 찾아 반환한다.
    b = findParent(b); // b의 루트 노드를 찾아 반환한다.
    if(a < b) parent[b] = a; // b의 집합을 a의 집합에 이어 붙이면서, 동시에 루트 노드를 a로 설정한다.
    else parent[a] = b;
  }
  ```

### DisjointSet을 활용한 사이클 확인
신기한 점은 `DisjointSet`을 이용해서 `Cycle` 여부를 판별할 수 있다. 어떤 원소 A가 포함되어 있는 집합과, B가 포함되어 있는 집합이 서로 사이클인지 아닌지 확인하는 방법은
두 원소의 `find`연산을 실행한 후 그 결과가 같다면 서로 사이클이고, 아니면 사이클 관계가 아닌 것이다.
```cpp
if(findParent(a) != findParent(b)) cout<<"Cycle이 아니다.\n";
else cout<<"Cycle이다!\n";
```

### 크루스칼 알고리즘 (Kruskal Algorithm)
`신장 트리`는 하나의 그래프가 있을 때 모든 노드를 포함하면서 사이클이 존재하지 않는 부분 그래프를 의미한다.     
신장 트리 중에서 최소 비용으로 만들 수 있는 신장 트리를 찾는 알고리즘인 크루스칼에 대해서 알아보자.    
동작 방식은 다음과 같다.
1. 간선 데이터를 비용에 따라 오름차순으로 정렬한다. (이 알고리즘은 정렬 비용이 가장 큰 비중을 둔다.)
2. 간선을 하나씩 확인하면서 현재의 간선을 추가했을 때, 사이클이 발생하는지 확인한다. `find`연산    
  2-1. 사이클이 발생하지 않는 경우 최소 신장 트리에 포함시킨다. `union` 연산    
  2-2. 사이클이 발생하는 경우 최소 신장 트리에 포함시키지 않는다.    
  
이 알고리즘에서 중요한 점은 가장 거리가 짧은 간선부터 차례대로 집합에 추가시키되, 추가하려는 간선이 사이클을 발생시키는 간선이라면 집합에 포함시키지 않고, 사이클을 발생시키지 않는다면
집합에 포함시키는 방식으로 진행한다. 그렇게 포함시키면서 해당 비용을 결과 변수에 더하다보면, 최종적으로 최소 신장 트리를 만드는 최소 비용을 얻을 수 있게 된다.    
* 간선을 오름차순으로 정렬하는 코드는 `<algorithm>`헤더에 sort 함수를 사용하면 간단하게 구현이 가능하다.
```cpp
sort(edges.begin(), edges.end());
```
* 해당 간선을 추가할 때 사이클의 발생 여부 확인은 `DisjointSet`을 이용하면 쉽게 구현할 수 있다.
```cpp
for(int i = 0; i < e; i++){
  int cost = get<0>(edges[i]); // 이 때 튜플의 상태는 {cost, a, b} a -> b로 가는 비용이 cost
  int a = get<1>(edges[i]);
  int b = get<2>(edges[i]);
  if(findParent(a) != findParent(b)){ // 사이클이 발생하지 않는다면
    unionParent(a,b);   // a의 집합과 b의 집합을 서로 합쳐주고
    answer += cost;     // 그 때의 드는 비용을 결과 변수에 더해준다.
  }
}
```

* 크루스칼의 시간 복잡도는 O(ElogE)    
크루스칼 알고리즘의 비중이 제일 큰 부분은 바로 간선을 오름차순으로 정렬하는 비용이다. 이 때 간선의 개수가 E개일 때, 정렬의 시간복잡도는 O(NlogN)이므로 결과적으로 O(ElogE)가 된다.  
이는 DisjointSet 알고리즘의 시간 복잡도가 정렬의 비용보다 영향이 크지 않으므로 무시된다.    

### 위상 정렬 (TopologySort)
`순서가 정해져 있는 일련의 작업을 차례대로 수행해야 할 때` 사용할 수 있는 알고리즘이다. 간단하게 생각하면 `스타크래프트`에서 `팩토리`를 짓기 위해서는 `커맨드센터`, `서플라이디팟`,
`배럭`을 우선적으로 지어져야만 `팩토리`를 지을 수 있듯이, 선수 과정이 필요할 때 사용하는 알고리즘이다.    
동작 방식은 다음과 같다.    
1. 진입차수가 0인 노드를 큐에 넣는다.
2. 큐가 빌 때까지 다음의 과정을 반복한다.    
  2-1 큐에서 원소를 꺼내 해당 노드에서 출발하는 간선을 그래프에서 제거한다.    
  2-2 새롭게 진입차수가 0이 된 노드를 큐에 넣는다. (2-1에서 제거로 인해 새롭게 진입차수가 0인 노드가 있을 수 있다.)    
  
주의할 점은 모든 원소를 방문하기 전에 큐가 비게 된다면 사이클이 존재한다고 판단할 수 있다. 이는 사이클이 존재하게 되면 서로의 진입차수는 1에서 0으로 떨어질 수 없기 때문이다. 
그렇기 때문에 사이클이 존재하는 경우 사이클에 포함되어 있는 원소 중에서 어떠한 원소도 큐에 들어가지 못하게 된다.    
또, 재밌는 점은 정답이 꼭 한개만은 아니라는 점이다. 정답의 경우의 수도 여러가지 일 수 있다. 이는 큐에 새롭게 들어가는 원소가 2개 이상인 경우가 있다면 가능하다.    

* 진입차수(indegree)의 개념을 알아보자.    
특정한 한 노드로 `들어오는` 간선의 개수를 의미한다. 예를 들어 A라는 노드와 B라는 노드가 다음과 같이 연결되어 있을 때(A -> B)    
A의 indegree는 0이고, B의 indegree는 1이다.

* 진입차수가 0인 노드를 큐에 넣는 방법은 다음과 같다.    
```cpp
for(int i = 1; i <= v; i++){
  if(indegree[i] == 0) q.push(i);
}
```

* 큐에서 원소를 꺼내 해당 노드에서 출발하는 간선을 그래프에서 제거하는 방법은 다음과 같다.
```cpp
int now = q.front();
q.pop();
for(int i = 0; i < graph[now].size(); i++){
  int next = graph[now][i]; // now 를 A, next 를 B라고 하면, A -> B 관계에서 간선을 삭제한다는 과정에서 보면 된다.
  indegree[next]--;  // 이 부분이 진입차수를 제거하는 부분이다.
  if(indegree[next] == 0){ // 만약에 새롭게 진입차수가 0이 되는 노드라면 큐에 넣어준다.
    q.push(next);
  }
}
```

* 위상 정렬의 시간 복잡도는 O(V + E)    
차례대로 모든 노드를 확인하면서, 해당 노드에서 출발하는 간선을 차례대로 제거하는 동작이므로 노드와 간선을 모두 확인한다는 측면에서 O(V + E)의 시간이 소요되는 것이다.