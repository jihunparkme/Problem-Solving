
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
