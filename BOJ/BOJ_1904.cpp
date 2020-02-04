#include <iostream>
#include <cstring>

using namespace std;

int MOD = 15746;
int fb[1000001] = { 0, 1, 2 };

int main() {
	// Improving iostream performance
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int n;
	cin >> n;

	for (int i = 3; i <= n ; i++) {
		fb[i] = (fb[i - 1] + fb[i - 2]) % MOD;
	}

	cout << fb[n];

	return 0;
}