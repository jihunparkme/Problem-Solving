#include <cstdio>
#include <algorithm>
using namespace std;

int main(void)
{
	int i, h1, h2, h3, d1, d2;
	
	scanf("%d%d%d%d%d", &h1, &h2, &h3, &d1, &d2);

	printf("%d\n", min(min(h1, h2), h3) + min(d1, d2) - 50);

	return 0;
}