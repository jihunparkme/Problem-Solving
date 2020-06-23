#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, i;
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	vector<pair<int, int> > vp(n);
	for (i = 0; i < n; i++) 
		scanf("%d %d", &vp[i].first, &vp[i].second);
	

	sort(vp.begin(), vp.end());

	for (i = 0; i < n; i++)
		printf("%d %d\n", vp[i].first, vp[i].second);

	return 0;
}