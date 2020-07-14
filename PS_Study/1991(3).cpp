#include <iostream>
#include <cstdio>

using namespace std;

char node[26][2];

void preorder(char root)
{
	if (root == '.') return;

	cout << root;
	preorder(node[root - 65][0]);
	preorder(node[root - 65][1]);
}

void inorder(char root)
{
	if (root == '.') return;

	inorder(node[root - 65][0]);
	cout << root;
	inorder(node[root - 65][1]);
}

void postorder(char root)
{
	if (root == '.') return;

	postorder(node[root - 65][0]);
	postorder(node[root - 65][1]);
	cout << root;
}

int main(void)
{
	int n;
	char root, left, right;
	//freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> root >> left >> right;
		node[root - 65][0] = left;
		node[root - 65][1] = right;
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	cout << '\n';
}