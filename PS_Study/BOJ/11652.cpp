#include <cstdio>
#include <map>
using namespace std;
#define x first
#define y second

int main(void)
{
	int n, i, mxCnt = 0;
	long long a, mxVal = 0;

	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);

	map<long long, int> m;
	map<long long, int>::iterator iter;

	for (i = 1; i <= n; i++) {
		scanf("%lld", &a);
		iter = m.find(a);

		if (iter == m.end())	// 해당 key가 없다면 end()를 가리킴
			m.insert({ a, 1 });
		else
			iter->y++;
	}

	for (auto it : m) {
		if (it.y > mxCnt) {
			mxCnt = it.y;
			mxVal = it.x;
		}
	}

	printf("%lld\n", mxVal);

	return 0;
}