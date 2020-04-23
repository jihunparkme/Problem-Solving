#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char a[8];

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int i, c = 0, h = 0;

	scanf("%s", &a);

	for (i = 1; a[i] != 'H'; i++)
		c = c * 10 + (a[i]-48);
	
	if (!c)
		c = 1;
	
	for (i = i+1; a[i] != '\0'; i++)
		h = h * 10 + (a[i]-48);

	if (!h)
		h = 1;

	printf("%d\n", c * 12 + h);

	return 0;
}