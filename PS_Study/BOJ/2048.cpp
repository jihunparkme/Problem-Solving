#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, res = -21470000;
vector<vector<int>> Board;

vector<vector<int> > Rotate(vector<vector<int> > B)
{
	int i, j;

	vector<vector<int> > NB(N, vector<int>(N, 0));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			NB[j][N - i - 1] = B[i][j];
		}
	}

	return NB;
}

vector<int> Combine(vector<int> lst)
{
	int i;
	vector<int> vt1, vt2;
	// 0이 아닌 숫자만 모아서
	for (auto i : lst)
		if (i)
			vt1.push_back(i);

	// 합치기
	for (i = 1; i < vt1.size(); i++)
	{
		if (vt1[i - 1] == vt1[i])
		{
			vt1[i - 1] *= 2;
			vt1[i] = 0;
		}
	}

	// 다시 0이 아닌 숫자만 모아서
	for (auto i : vt1)
		if (i)
			vt2.push_back(i);

	for (i = 0; vt2.size() != N; i++)
		vt2.push_back(0);

	return vt2;
}

int DFS(vector<vector<int> > B, int cnt)
{
	int i, j;

	// Board에서 가장 큰 수 찾기
	for (i = 0; i < N * N; i++)
		res = max(res, B[i/N][i%N]);

	if (!cnt)
		return res;
	
	for (i = 0; i < 4; i++)
	{
		vector<vector<int> > X(N);
		for (j = 0; j < N; j++) 
			X[j] = Combine(B[j]);

		if (X != B)
			res = max(res, DFS(X, cnt - 1));
		
		B = Rotate(B);
	}
	
	return res;
}

int main(void)
{
	int i, j;

	scanf("%d", &N);
	Board.resize(N, vector<int>(N, 0));
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &Board[i][j]);

	printf("%d\n", DFS(Board, 5));

	return 0;
}