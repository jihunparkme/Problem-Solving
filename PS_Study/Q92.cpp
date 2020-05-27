#include <cstdio>

int table[50];

int DFS(int n)
{
	if (table[n]) return table[n];
	if (n == 1 || n == 2)
		return n;
	else
		return table[n] = DFS(n - 2) + DFS(n - 1);
}

int main(void)
{
	int N;
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &N);

	printf("%d\n", DFS(N));

	return 0;
}