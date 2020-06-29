#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	int n, x;
	string qr;
	freopen("input.txt", "rt", stdin);
	cin >> n;

	stack<int> st;
	while (n--) {
		cin >> qr;

		if (qr == "push") {
			cin >> x;
			st.push(x);
		}
		else if (qr == "pop") {
			if (st.size() == 0) cout << "-1" << '\n';
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (qr == "size") 
			cout << st.size() << '\n';
		else if (qr == "empty") {
			if(st.empty()) cout << "1" << '\n';
			else cout << "0" << '\n';
		}
		else if (qr == "top") {
			if (st.size() == 0) cout << "-1" << '\n';
			else cout << st.top() << '\n';
		}
	}

	return 0;
}