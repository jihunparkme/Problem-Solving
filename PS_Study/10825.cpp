#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct student
{
	char name[15];
	int k;
	int e;
	int m;
};

bool cmp(const student& s1, const student& s2)
{
	if (s1.k == s2.k && s1.e == s2.e && s1.m == s2.m) {
		if (strcmp(s1.name, s2.name) < 0) return true;
		return false;
	}
	else if (s1.k == s2.k && s1.e == s2.e) return s1.m > s2.m;
	else if (s1.k != s2.k) return s1.k > s2.k;
	else return s1.e < s2.e;
}

int main(void)
{
	int n, i;
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	student* st = new student[n];

	for (i = 0; i < n; i++)
		cin >> st[i].name >> st[i].k >> st[i].e >> st[i].m;
	
	sort(st, st + n, cmp);

	for (i = 0; i < n; i++)
		cout << st[i].name << '\n';

	delete[] st;
	return 0;
}