#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define f first
#define s second

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.s != b.s) return a.s < b.s;
	else return a.f < b.f;
}

int main(void)
{
	int n, i;
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	vector<pair<int, int> > vp(n);
	for (i = 0; i < n; i++) 
		scanf("%d %d", &vp[i].f, &vp[i].s);
	
	sort(vp.begin(), vp.end(), cmp);

	for (i = 0; i < n; i++)
		printf("%d %d\n", vp[i].f, vp[i].s);

	return 0;
}