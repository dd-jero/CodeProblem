# Union-Find(유니온-파인드)

- 서로소 집합을 관리하기 위한 데이터 구조
- 여러 개의 원소가 각각 독립적인 집합에 속해 있을 때, 두 원소가 동일한 집합에 속하는지 판별하거나 두 집합을 합치는 연산을 효율적으로 수행

## 주요 연산

- Find(): 특정 원소가 속합 집합을 찾는다.
- Union: 서로 다른 두 집합을 하나의 집합으로 합친다.

## 최적화 기법

- 경로 압축 (Pass Compression)
    - Find 연산 시 경로 상의 모든 노드를 루트 노드로 직접 연결하여 트리의 높이를 줄이는 방법
    - 최악의 경우 그래프가 편향된 상태가 주어진 경우 O(N)이 걸린다. 따라서 경로 압축을 활용하면 상수 시간 내에 연산이 가능하다.
- Union by Rank
    - 두 트리의 깊이를 비교하여 깊이가 작은 트리를 더 깊은 트리 밑에 붙이는 방법
    - 단순하게 합치면 트리의 깊이가 증가할 수 있기 때문에 연산이 복잡해질 수 있음. 따라서 트리의 깊이를 비교해서 얕은 트리를 깊은 트리 밑에 붙임으로써 트리의 높이가 증가하는 것을 방지한다.

## 코드

```cpp
#include <iostream>
using namespace std;

int parent[100001];

int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]); // 경로 압축
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) return; // 이미 같은 집합이므로 무시

	if (x > y) parent[y] = x;
	else parent[x] = y;
}

bool IsUnion(int x, int y) {
	x = Find(x);
	y = Find(y);
	return x == y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b;
	int n, m;
	cin >> n >> m;

	// 자기 자신을 루트로 초기화
	for (int i = 0;i <= n;i++) {
		parent[i] = i; 
	}

	for (int i = 0;i < m;i++) {
		cin >> a >> b;
		Union(a, b);
	}

	return 0;
}
```

## Weighted Union-Find

> 두 집합을 합칠 때, 각 집합의 크기를 비교하여 크기가 작은 집합을 큰 집합의 하위 트리에 붙인다. 이를 통해 트리의 높이가 증가하는 것을 방지한다.
> 
- Union by Rank 기법 중 가장 효율적으로 메모리를 관리할 수 있는 방법
- parent 배열 하나만으로 활용
- parent 배열을 음수 값으로 초기화 하여 트리의 크기와 부모 노드에대한 정보를 동시에 저장하는 방식
    - 음수 값: 현재 노드가 루트 노드임을 나타내며, 음수의 절대값이 해당 집합의 크기를 나타 낸다.
    - 양수 값: 부모 노드의 인덱스를 나타냄.

### 작동 방식

- 초기화: 모든 원소가 자기 자신을 가리키도록 설정 ⇒ -1로 초기화하여 각 원소가 자기 자신이 루트이며 크기가 1임을 의미
- Find: 트리의 루트를 찾고, 경로 압축으로 트리의 높이를 줄임.
- Union: 두 집합의 루트를 찾고, 크기를 비교하여 더 작은 집합을 더 큰 집합에합침. 이 때 parent 배열 값을 갱신하여 트리의 크기도 업데이트

### 코드

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int parent[1001];

int Find(int x) {
	if (parent[x] < 0) return x; // 음수 값을 가지면 x가 루트 노드
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) return; // 이미 같은 집합이므로 무시

	if (parent[x] < parent[y]) { // 음수 값의 절대 값은 집합의 크기를 의미
		parent[x] += parent[y]; // 집합 x의 크기 증가
		parent[y] = x; // y가 x를 루트로 가리킴.
	}
	else { // 집합 y의 크기가 더 크면
		parent[y] += parent[x]; // y의 크기 증가
		parent[x] = y; // x는 y를 루트로 가리킴.
	}
}

int IsUnion(int x, int y) {
	x = Find(x);
	y = Find(y);

	return x == y;
}

int size(int x) {
	return -parent[Find(x)];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b;
	int n;
	cin >> n;

	// parent 배열을 -1로 초기화: 자기 자신을 루트로, 집합 크기 1
	fill(parent, parent + n, -1);

	for (int i = 0;i < n;i++) {
		cin >> a >> b;
		Union(a, b);
	}

	return 0;
}
```

---

출처: [https://velog.io/@gleaming9/Algorithm-유니온-파인드Union-Find-C](https://velog.io/@gleaming9/Algorithm-%EC%9C%A0%EB%8B%88%EC%98%A8-%ED%8C%8C%EC%9D%B8%EB%93%9CUnion-Find-C)
