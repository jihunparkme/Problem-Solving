#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int> > pz;
vector<pair<int, int> > hs;
int ch[20], m, res = 2147000000, dis, sum = 0;

void DFS(int L, int s) {
	if (L == m) {
		sum = 0;
		for (int i = 0; i < hs.size(); i++) {
			int x1 = hs[i].first;
			int y1 = hs[i].second;
			dis = 2147000000;
			for (int j = 0; j < m; j++) {
				int x2 = pz[ch[j]].first; 
				int y2 = pz[ch[j]].second;
				dis = min(dis, abs(x1 - x2) + abs(y1 - y2));
			}
			sum = sum + dis;
		}
		if (sum < res) res = sum;
	}
	else {
		for (int i = s; i < pz.size(); i++)
		{
			ch[L] = i;
			DFS(L + 1, i + 1);
		}
	}
}

int main() {
	int n, i, j, a;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &a);
			if (a == 1) hs.push_back(make_pair(i, j));
			else if (a == 2) pz.push_back(make_pair(i, j));
		}
	}
	DFS(0, 0);
	printf("%d\n", res);
	return 0;
}