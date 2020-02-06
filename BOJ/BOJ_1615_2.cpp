#include <iostream>
#include <vector>

using namespace std;

int N, M;	// node, edge
vector<int> edge;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int m = M;

	// edge의 정보를 vector에 저장
	while (m--) {
		int e1, e2;
		cin >> e1 >> e2;

		edge.push_back(e2);
	}

	// insert sort
	int rst = 0;
	for (unsigned int i = 1; i < edge.size(); i++) {
		int key = edge[i], j = i - 1;
		while (j >= 0 && key < edge[j]) {
			edge[j + 1] = edge[j];
			j--; rst++;
		}
		edge[j + 1] = key;
	}

	cout << rst << '\n';

	return 0;
}

/*
- A1<A2, B1>B2 또는 A1>A2, B1<B2를 만족한다면 두 에지는 교차

[접근]
완전탐색을 해야하는데 단순하게 풀어서는 시간초과가 발생하므로,
최적화된 방법이 필요할 듯 하다.

[시도]
1.완전 탐색으로 접근
- 에지의 데이터를 vector에 저장
- vector의 데이터를 순차적으로 탐색
- 시간 초과.. O(N^2)

2. 삽입정렬의 비교 횟수를 활용하여 결과값을 구할 수 있다는 것을 알아냈지만,
- 시간 초과.. 삽입 정렬도 최악의 상황은 O(N^2)

3. 세그먼트 트리

[배운점]
*/