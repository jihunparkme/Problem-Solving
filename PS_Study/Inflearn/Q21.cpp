#include <cstdio>

int A[10], B[10];
char rst[10];

int main(void)
{
	freopen("input.txt", "rt", stdin);
	int i, scrA = 0, scrB = 0;

	for (i = 0; i < 10; i++)
		scanf("%d", &A[i]);

	for (i = 0; i < 10; i++)
		scanf("%d", &B[i]);
	
	for (i = 0; i < 10; i++)
	{
		if (A[i] > B[i])
		{
			scrA += 3;
			rst[i] = 'A';
		}
		else if (A[i] < B[i])
		{
			scrB += 3;
			rst[i] = 'B';
		}
		else
		{
			scrA++;
			scrB++;
			rst[i] = 'D';
		}
	}

	printf("%d %d\n", scrA, scrB);

	if (scrA > scrB)
		printf("A\n");
	else if (scrA < scrB)
		printf("B\n");
	else
	{
		for (i = 9; i >= 0; i--)
		{
			if (rst[i] == 'A' || rst[i] == 'B')
			{
				printf("%c\n", rst[i]);
				break;
			}
		}

		if (i < 0)
			printf("D\n");
	}

	return 0;
}