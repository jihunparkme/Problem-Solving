#include <iostream>

using namespace std;

const int MAX = 1000000;
int A[MAX], B[MAX];

int main()
{
	// Improving iostream performance
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	// input array A and B
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}

	// Alternative to double iteration
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (A[i] > B[j]) cout << B[j++] << ' ';
		else cout << A[i++] << ' ';
	}

	while (i < n) cout << A[i++] << ' ';
	while (j < m) cout << B[j++] << ' ';

	return 0;
}