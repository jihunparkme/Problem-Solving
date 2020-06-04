#include <cstdio>

int A[100], B[100];

int main(void)
{
	freopen("input.txt", "rt", stdin);
	int n, i;
	char rst = ' ';

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	
	for (i = 0; i < n; i++)
		scanf("%d", &B[i]);

	for (i = 0; i < n; i++)
	{
		int tmp = A[i] + B[i];
		int who = A[i] - B[i];

		if (A[i] == B[i])
			rst = 'D';
		else if (tmp == 3)
			rst = who < 0 ? 'B' : 'A';
		else if (tmp == 4)
			rst = who < 0 ? 'A' : 'B';
		else if (tmp == 5)
			rst = who < 0 ? 'B' : 'A';

		printf("%c\n", rst);
	}

	return 0;
}