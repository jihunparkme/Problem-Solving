#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Lecture
{
	int money;
	int day;
	Lecture(int a, int b)
	{
		money = a;
		day = b;
	}
	bool operator<(const Lecture& b) const
	{
		return day > b.day;
	}

};

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, i, j, a, b, income = 0, rest = 0;
	vector<Lecture> vt;
	priority_queue <int> pQ;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);

		vt.push_back(Lecture(a, b));
	}

	sort(vt.begin(), vt.end());

	rest = vt[0].day;
	j = 0;
	for (i = rest; i >= 1; i--)
	{
		for (; j < n; j++)
		{
			if (vt[j].day < i)
				break;

			pQ.push(vt[j].money);
		}

		if (!pQ.empty())
		{
			income += pQ.top();
			pQ.pop();
		}
	}

	printf("%d\n", income);

	return 0;
}