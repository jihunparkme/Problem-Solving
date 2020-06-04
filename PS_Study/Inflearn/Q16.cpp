#include <cstdio>

int alpaA[123], alpaB[123];

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int i;
	char a[100], b[100];

	scanf("%s %s", &a, &b);

	for (i = 0; a[i] != '\0'; i++)
		alpaA[a[i]]++;

	for (i = 0; b[i] != '\0'; i++)
		alpaB[b[i]]++;

	bool isSame = true;

	for (i = 65; i < 123; i++)
	{
		if (alpaA[i] != alpaB[i])
		{
			isSame = false;
			break;
		}
	}

	if (isSame)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}