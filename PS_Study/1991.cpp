#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define x first
#define y second
#define MAX 2147000000
#define MIN -2147000000
int max(int p, int q) { return p > q ? p : q; }

int map[54];

int main(void)
{
	int n, i;
	char root, left, right;
	freopen("input.txt", "rt", stdin);
	cin >> n;
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	for (i = 0; i < n; i++) {
		cin >> root >> left >> right;
		
	}

	return 0;
}


/*
#include <iostream>
using namespace std;

int n;

struct node {
    char left;
    char right;
};

struct node arr[100];

void preorder(char root) {
    if (root == '.')
        return;
    else {
        cout << root;
        preorder(arr[root].left);
        preorder(arr[root].right);
    }
}

void inorder(char root) {
    if (root == '.')
        return;
    else {
        inorder(arr[root].left);
        cout << root;
        inorder(arr[root].right);
    }
}

void postorder(char root) {
    if (root == '.')
        return;
    else {
        postorder(arr[root].left);
        postorder(arr[root].right);
        cout << root;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;

    char t1, t2, t3;

    for (int i = 1; i <= n; i++) {
        cin >> t1 >> t2 >> t3;
        arr[t1].left = t2; arr[t1].right = t3;
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
    cout << "\n";

    return 0;
}

</iostream>
*/