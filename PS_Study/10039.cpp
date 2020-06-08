#include <cstdio>
using namespace std;

int main(void)
{
	int i, sum = 0, std;

	for (i = 0; i < 5; i++) {
		scanf("%d", &std);

		sum += std >= 40 ? std : 40;
	}

	printf("%d\n", sum / 5);

	return 0;
}