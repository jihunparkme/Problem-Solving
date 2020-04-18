#include <iostream>

using namespace std;

int N;
long long fb[91];

int main()
{
	// Improving iostream performance
	ios::sync_with_stdio(false);
	cin >> N;

	fb[1] = 1;
	for (int i = 2; i <= N; i++) {
		fb[i] = fb[i - 1] + fb[i - 2];
;	}

	cout << fb[N];

	return 0;
}

