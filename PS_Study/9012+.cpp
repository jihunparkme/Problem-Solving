#include <cstdio>

char str[55];

int main(void)
{
	int tc, i;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &tc);

	while (tc--) {
		scanf("%s", str);
		int cur = 0;
		for (i = 0; str[i] && cur >= 0; i++) 
			str[i] == '(' ? cur++ : cur--;
			printf("%s\n", (cur != 0 ? "NO" : "YES"));
	}

	return 0;
}