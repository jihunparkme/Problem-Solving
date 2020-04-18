#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;


ll sum(vector<ll>& tree, int idx) 
{
	int rst = 0;

	while (idx > 0)
	{
		rst += tree[idx];
		// 다음 구간을 찾기 위해 최하위 비트 삭제 : idx-1 이후 AND 연산
		// idx &= (idx - 1);
		idx -= (idx & -idx);
	}

	return rst;
}

void update(vector<ll> &tree, int idx)
{
	while (idx < tree.size())
	{
		tree[idx] += 1;
		idx += (idx & -idx);
	}
}

int main()
{
	int n, m;	// n(5) : node 개수, m(6) : edge 개수

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	// edge 의 정보를 저장하는 vector 생성
	vector<pair<ll, ll>> e(m);
	// 펜윅 트리는 n 개의 수에 대한 부분합을 n 개의 숫자에 저장
	vector<ll> tree(n + 1);

	// edge 의 정보를 vector<pair> 에 저장
	for (int i = 0; i < m; i++)
	{
		cin >> e[i].first >> e[i].second;
	}
	// edge 정보를 i 기준으로 정렬
	sort(e.begin(), e.end());

	ll rst = 0;

	for (int i = 0; i < m; i++)
	{ // node 의 개수만큼 반복
		int spot = e[i].second; // 연결할 지점

		// tree 를 만들면서 rst 값을 return
		rst += sum(tree, n) - sum(tree, spot);

		// spot 에 해당하는 index_node 값에 +1
		tree[spot] += 1;
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
1. 완전 탐색으로 접근.
- 예상하였듯이 시간 초과. O(N^2)

2. 삽입정렬의 비교 횟수를 활용하여 결과를 도출해 낼 수 있다는 규칙을 발견.
- 삽입 정렬도 최악의 상황은 O(N^2) 이므로 시간 초과.

3. 세그먼트 트리
- 먼저 입력 (i, j)를 i 기준으로 정렬
- j 에 해당하는 node 를 찾아가서 +1을 해주는데, j 자리를 찾아가면서 왼쪽 자식 노드로 내려갈 경우, 오른쪽 자식 노드의 값을 더해주어야 한다.(이미 그려진 edge 를 지나가므로)
단, j 자리를 찾아갈 때 오른쪽 자식 노드로 내려갈 경우, 왼쪽 자식 노드의 값을 더해 줄 필요는 없음.(edge 가 안 겹치므로)
ex) j = 1일 경우, 내려가는 길의 오른쪽 자식 노드의 해당하는 [4~5범위 노드의 값] + [노드 3의 값] + 노드 2의 값] 을 계속해서 더해주어야 한다.
- j 에 해당하는 node 의 값에 +1 과 동시에 특정 spot 으로 생긴 edge 와 교차하는 개수를 최종 rst 변수에 쌓아주고,
상위 노드의 값들을 update 해준다.

4. 펜윅 트리를 적용하여 시도해보았는데, 펜윅 트리는 홀수번째 노드가 다 없어진 형태이고, 부분 합이 노드에 저장되어있어서
홀수번째 노드에 접근이 필요한 이 문제는 적용할 수 없는 것 같다.

[배운점]
- O(logN)의 세그먼트 트리로 탐색을 구현해보면서 구간 트리에 대해 공부해볼 수 있었습니다. (자세한 동작은 코드 주석에 기록)
- 두 객체를 하나의 하나의 객체로 묶어주는 C++의 pair 클래스를 알게 되었습니다.
- 세그먼트 트리의 변형 펜윅 트리(바이너리 인덱스 트리)도 알게 되었고 비록 이 문제를 펜윅 트리에 적용하여 결과를 도출해낼 수 없었지만 
펜윅 트리에 대해 공부해볼수 있었습니다.
*/