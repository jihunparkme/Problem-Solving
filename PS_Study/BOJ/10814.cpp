#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define x first
#define y second

struct member
{
	int age;
	char name[101];
	int idx;
};

bool cmp(member& m, member& m2) {
	if (m.age != m2.age) return m.age < m2.age;
	else return m.idx < m2.idx;
}

int main(void)
{
	int n, i;
	// freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	vector<member> vp(n);
	for (i = 0; i < n; i++) {
		scanf("%d %s", &vp[i].age, vp[i].name);
		vp[i].idx = i;
	}
	
	sort(vp.begin(), vp.end(), cmp);

	for (i = 0; i < n; i++)
		printf("%d %s\n", vp[i].age, vp[i].name);

	return 0;
}