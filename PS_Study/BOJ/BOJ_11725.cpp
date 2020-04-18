#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Maximum number of nodes
#define MAX 100001

int N;
int parent[MAX];	// save parent nodes
bool chk[MAX];		// check visited nodes
vector<int> arr[MAX];	// tree list

int main()
{
	// Improving iostream performance
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int n1, n2;

		cin >> n1 >> n2;

		arr[n1].push_back(n2); arr[n2].push_back(n1);
	}

	queue<int> q;

	parent[1] = 0; // Root has no parent
	chk[1] = true;
	q.push(1);

	// BFS process
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		for (int y : arr[x]) // range-based for
		{
			if (!chk[y])
			{
				chk[y] = true;
				parent[y] = x;
				q.push(y);
			}
		}
	}

	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";

	return 0;
}