#include <cstdio>
#include <stack>
using namespace std;

char str[100001];

int main(void)
{
	int i, res = 0, prev = 0;;
	// freopen("input.txt", "rt", stdin);
	scanf("%s", str);

	stack<int> st;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(')	st.push(1);
		else { // 이전에 ')'였는데, 또 ')'라면 +1
			if (prev == ')') { 
				st.pop();
				res += 1;
			} // 레이져가 생기면 현재 stack size 누적
			else {
				st.pop();
				res += st.size();
			}
		}

		prev = str[i];
	}

	printf("%d\n", res);

	return 0;
}