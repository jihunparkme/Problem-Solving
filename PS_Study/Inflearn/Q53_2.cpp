#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int stack[1000];
int top;

void push(int n)
{
	stack[++top] = n;
}

int pop()
{
	return stack[top--];
}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, k, mod;

	scanf("%d %d", &n, &k);

	top = -1;

	while (n)
	{
		mod = n % k;
		n /= k;

		push(mod);
	}

	if (k == 16)
	{
		while (top != -1)
		{
			int tmp = pop();
			if (tmp >= 10)
				printf("%c", tmp + 55);
			else
				printf("%d", tmp);
		}
	}
	else
	{
		while (top != -1)
			printf("%d", pop());
	}

	return 0;
}