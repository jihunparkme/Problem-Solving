#include <cstdio>

int main(void)
{
	int N, i, score = 0, bonus = 0;
	char ox[10001];

	scanf("%d", &N);
	scanf("%s", &ox);
	
	for (i = 0; i < N; i++)
	{
		if (ox[i] == 'O')
		{
			score += i + 1 + bonus;
			bonus++;
		}
		else
			bonus = 0;
	}

	printf("%d\n", score);

	return 0;
}