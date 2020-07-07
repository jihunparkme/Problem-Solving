#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main(void)
{
	int n, x;
	string qr;
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;

	queue<int> q;
	while (n--) {
		cin >> qr;

		if (qr == "push") {
			cin >> x;
			q.push(x);
		}
		else if (qr == "pop") {
			if (q.size() == 0) printf("-1\n");
			else {
				printf("%d\n", q.front()); q.pop();
			}
		}
		else if (qr == "size") printf("%d\n", q.size());
		else if (qr == "empty") {
			if (q.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (qr == "front") {
			if (q.size() == 0) printf("-1\n");
			else {
				printf("%d\n", q.front());
			}
		}
		else if (qr == "back") {
			if (q.size() == 0) printf("-1\n");
			else {
				printf("%d\n", q.back());
			}
		}
	}

	return 0;
}