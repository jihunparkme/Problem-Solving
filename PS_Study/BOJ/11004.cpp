#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int a, k, i, x;
	freopen("input.txt", "rt", stdin);
	scanf("%d %d", &a, &k);
	vector<int> v;

	for (i = 0; i < a; i++) {
		scanf("%d", &x);
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	printf("%d\n", v[k - 1]);

	return 0;
}