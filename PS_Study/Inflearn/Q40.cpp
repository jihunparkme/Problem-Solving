#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void insertionSort(vector<int>& v, int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        j = i - 1;
        key = v[i];

        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = key;
    }
}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int an, bn, ap = 0, bp = 0, i;

	scanf("%d", &an);
	vector<int> a(an);
	for (i = 0; i < an; i++)
		scanf("%d", &a[i]);

    insertionSort(a, an);

	scanf("%d", &bn);
	vector<int> b(bn);
	for (i = 0; i < bn; i++)
		scanf("%d", &b[i]);

    insertionSort(b, bn);

    while (ap < an && bp < bn)
    {
        if (a[ap] == b[bp])
        {
            printf("%d ", a[ap]);   
            ap++, bp++;
        }
        else if (a[ap] < b[bp])
            ap++;
        else
            bp++;
    }

    puts("");

	return 0;
}