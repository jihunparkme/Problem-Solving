#include <iostream>

using namespace std;

int tc, N;
int fb[42] = {1};

int main() {
	ios::sync_with_stdio(false);
	cin >> tc;

	for (int i = 2; i < 42; i++) {
		fb[i] = fb[i - 1] + fb[i - 2];
	}

	while (tc--) {
		cin >> N;
		
		cout << fb[N] << ' ' << fb[N+1] << '\n';
	}

	return 0;
}