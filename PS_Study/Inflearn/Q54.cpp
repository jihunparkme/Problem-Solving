#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

char str[30];

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int i;
	stack<int> s;

	scanf("%s", &str);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
			s.push(str[i]);
		else
		{
			if (s.empty())
			{
				printf("NO\n");

				return 0;
			}
			else
				s.pop();
		}
	}

	if (s.empty())
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}