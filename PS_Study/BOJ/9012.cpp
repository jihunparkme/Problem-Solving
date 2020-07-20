#include <cstdio>

int main(void)
{
	int tc, i;
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &tc);

	while (tc--) {
		char str[55];
		int cur = -1;
		bool flag = true;

		scanf("%s", str);
		for (i = 0; str[i] != '\0'; i++) {
			if (str[i] == '(') cur++;
			else {
				if (cur < 0) {
					printf("NO\n");
					flag = false;
					break;
				}
				else cur--;
			}
		}

		if (flag) {
			if (cur == -1)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}