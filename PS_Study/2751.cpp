#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, i;
	// freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	vector<int> v(n);
	for (i = 0; i < n; i++) 
		scanf("%d", &v[i]);
	
	sort(v.begin(), v.end());

	for (i = 0; i < n; i++)
		printf("%d\n", v[i]);

	return 0;
}