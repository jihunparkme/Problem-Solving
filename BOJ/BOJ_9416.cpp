#include <iostream>

using namespace std;

int tc;
int n;
long long padovan[101] = { 0,1,1,1,2 };

int main() {
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL), cout.tie(NULL);

	cin >> tc;

	for (int i = 5; i <= 101; i++) {
		padovan[i] = padovan[i - 3] + padovan[i - 2];
	}

	while (tc--) {
		cin >> n;
		cout << padovan[n] << '\n';
	}
}