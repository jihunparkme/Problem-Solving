#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

const int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
int N, MP[105][105], ck[105][105], dist[105][105];

void dfs(int col, int idx) {
    int x = idx / (N + 1), y = idx % (N + 1);
    ck[x][y] = col;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (!xx || !yy || xx > N || yy > N || ck[xx][yy] || !MP[xx][yy]) continue;
        dfs(col, xx * (N + 1) + yy);
    }
} 

int main() {
    ios::sync_with_stdio(false); cin.tie();
    queue<pair<int, int> > point;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cin >> MP[i][j];
    }
    int idx = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (MP[i][j] && !ck[i][j]) {
                dfs(++idx, i * (N + 1) + j);
            }
        }
    }
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (ck[i][j]) {
                point.push({ i * (N + 1) + j, ck[i][j] });
                dist[i][j] = 0;
            }
        }
    }
    int ans = 10001;
    while (!point.empty()) {
        auto tp = point.front(); point.pop();
        int idx = tp.first, col = tp.second;
        int x = idx / (N + 1), y = idx % (N + 1);
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (!xx || !yy || xx > N || yy > N || ck[xx][yy] == col) continue;
            if (ck[xx][yy]) {
                ans = min(ans, dist[x][y] + dist[xx][yy]);
                continue;
            }
            ck[xx][yy] = col;
            dist[xx][yy] = dist[x][y] + 1;
            point.push({ xx * (N + 1) + yy, col });
        }
    }
    cout << ans << '\n';
}