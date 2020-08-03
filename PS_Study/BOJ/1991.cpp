#include <iostream>
#include <vector>
using namespace std;
#define left first
#define right second

vector<pair<char, char> > tree(100);

void preorder(char root)
{
	if (root == '.') return;

	cout << root;
	preorder(tree[root].left);
	preorder(tree[root].right);
}

void inorder(char root)
{
	if (root == '.') return;

	inorder(tree[root].left);
	cout << root;
	inorder(tree[root].right);
}

void postorder(char root)
{
	if (root == '.') return;

	postorder(tree[root].left);
	postorder(tree[root].right);
	cout << root;
}

int main(void)
{
	int n, i;
	char rot, lt, rt;
	freopen("input.txt", "rt", stdin);
	cin >> n;
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	for (i = 0; i < n; i++) {
		cin >> rot >> lt >> rt;
		tree[rot].left = lt;
		tree[rot].right = rt;
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	cout << "\n";

	return 0;
}