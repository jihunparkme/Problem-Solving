#include <cstdio>
#include <vector>

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, i, pre, now;
	
	scanf("%d", &n);
	std::vector<int> v(n);

	scanf("%d", &pre);

	for (i = 1; i < n; i++)
	{
		scanf("%d", &now);

		v[abs(now - pre)]++;

		pre = now;
	}

	bool isJumper = true;

	for (i = 1; i < n - 1; i++)
	{
		if (v[i] != 1)
		{
			isJumper = false;
		
			break;
		}
	}

	if (isJumper)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}                                                                                                         