#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n1, n2, i, p1 = 0, p2 = 0;

	scanf("%d", &n1);
	vector<int> v1(n1);
	for (i = 0; i < n1; i++)
		scanf("%d", &v1[i]);

	scanf("%d", &n2);
	vector<int> v2(n2);
	for (i = 0; i < n2; i++)
		scanf("%d", &v2[i]);

	while (p1 < n1 && p2 < n2)
	{
		if (v1[p1] <= v2[p2])
			printf("%d ", v1[p1++]);
		else
			printf("%d ", v2[p2++]);
	}

	while(p1 < n1) 
		printf("%d ", v1[p1++]);
	while (p2 < n2) 
		printf("%d ", v2[p2++]);

	return 0;
}