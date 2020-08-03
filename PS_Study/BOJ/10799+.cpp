#include <cstdio>
using namespace std;

char str[100005];

int main(void)
{
	int i, res = 0, stick = 0;
	// freopen("input.txt", "rt", stdin);
	scanf("%s", str);

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(')	stick++;
		else { 
			stick--;

			if (str[i - 1] == ')') res += 1;
			else res += stick;
		}
	}

	printf("%d\n", res);

	return 0;
}