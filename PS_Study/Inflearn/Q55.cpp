#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, i, tmp, seq = 1;
	vector<char> rst;
	stack<int> t;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);

		t.push(tmp);
		rst.push_back('P');

		while (!t.empty() && t.top() == seq)
		{
			t.pop();
			rst.push_back('O');
			seq++;
		}
	}

	if (!t.empty())
		printf("impossible");
	else
	{
		for (i = 0; i < rst.size(); i++)
		{
			printf("%c", rst[i]);
		}
	}

	return 0;
}