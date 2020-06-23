#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define x first
#define y second
#define MAX 2147000000
#define MIN -2147000000
int max(int p, int q) { return p > q ? p : q; }

struct student
{
	char name[11];
	int k;
	int e;
	int m;
};

bool cmp(student& s1, student& s2) 
{
	if (s1.k != s2.k) return s1.k > s2.k;
	else if (s1.k == s2.k) return s1.m < s2.m;
	else if (s1.k == s2.k && s1.e == s2.e) return s1.m > s2.m;
	else return s1.name < s2.name;
}

int main(void)
{
	int n, i;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	vector<student> vp(n);
	for (i = 0; i < n; i++) 
		scanf("%s %d %d %d", vp[i].name, &vp[i].k, &vp[i].e, &vp[i].m);
	
	sort(vp.begin(), vp.end(), cmp);

	for (i = 0; i < n; i++)
		printf("%s\n", vp[i].name);

	return 0;
}