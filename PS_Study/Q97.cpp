#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Blk {
	int area;
	int height;
	int weight;

	Blk(int a, int b, int c) {
		area = a;
		height = b;
		weight = c;
	}
	bool operator<(const Blk& b) const {
		return area > b.area;
	}
};

int main(void)
{
	int n, i, j, mx, a, b, c, res = 0;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	vector<Blk> blocks;
	vector<int> dp(n);

	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		blocks.push_back(Blk(a, b, c));
	}

	sort(blocks.begin(), blocks.end());
	dp[0] = blocks[0].height;
	res = dp[0];
	for (i = 1; i < n; i++) {
		mx = 0;

		for (j = i - 1; j >= 0; j--) {
			if (blocks[j].weight > blocks[i].weight && dp[j] > mx)
				mx = dp[j];
		}

		dp[i] = mx + blocks[i].height;
		if (res < dp[i])
			res = dp[i];
	}

	printf("%d\n", res);

	return 0;
}