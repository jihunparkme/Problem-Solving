#include <iostream>
#include <vector>

using namespace std;

int N, M;	// node 개수, edge 개수
vector<int> edge[2001];

// 교차 확인
int isIntersection(int a1, int b1, int a2, int b2) {
	if (a1 < a2 && b1 > b2) {
		return 1;
	}
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int i = 0, m = M;

	// edge의 정보를 vector에 저장
	while (m--) {
		int e1, e2;
		cin >> e1 >> e2;
		
		edge[i].push_back(e1);
		edge[i].push_back(e2);
		i++;
	}

	// 완전 탐색
	int rst = 0;
	for (int i = 0; i < M-1; i++) {
		for (int j = i+1; j < M; j++) {
			rst += isIntersection(edge[i][0], edge[i][1], edge[j][0], edge[j][1]);
		}
	}

	cout << rst << '\n';

	return 0;
}

/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;	// node 개수, edge 개수
int edge[2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int m = M, i = 0;

	// edge의 정보를 배열에 저장
	while (m--) {
		int e1, e2;
		cin >> e1 >> e2;

		edge[i] = e2;
		i++;
	}

	// 보완된 완전 탐색 2
	int rst = 0, a = 0;
	while (a < N) {
		for (int b = a + 1; b <= N; b++) {
			if (edge[a] > edge[b]) rst++;
		}
		a++;
	}

	cout << rst << '\n';

	return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;	// node 개수, edge 개수
vector<int> edge;
int edge_org[2001];

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

cin >> N >> M;

int m = M, i = 0;

// edge의 정보를 배열에 저장
while (m--) {
int e1, e2;
cin >> e1 >> e2;

edge.push_back(e2);
edge_org[i] = e2;
i++;
}

// 벡터 정렬
sort(edge.begin(), edge.end());

// 보완된 완전 탐색 3
int rst = 0, a = 0;
while (a < N) {
for (int b = 0; b < edge.size(); b++) {
if (edge_org[a] == edge[b]) {
edge.erase(edge.begin() + b);
break;
}
else rst++;
}
a++;
}

cout << rst << '\n';

return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
while(j >= 0 && key < edge[j]) {
edge[j+1] = edge[j];
j--; rst++;
}
edge[j + 1] = key;
}

cout << rst << '\n';

return 0;
}
*/
