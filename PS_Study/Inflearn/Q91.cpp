#include <cstdio>

int line[50] = { 0, 1, 2, };

int main(void)
{
	int N, i;
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &N);
	for (i = 3; i <= N; i++)
		line[i] = line[i - 2] + line[i - 1];

	printf("%d\n", line[N]);

	return 0;
}