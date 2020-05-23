import sys
sys.setrecursionlimit(10000)

dx, dy = [0, 1, -1, 0], [1, 0, 0, -1]
grd, ck = [], []
T = int(input())

def dfs(x, y):
    global grd, ck
    if ck[x][y] == 1:
        return
    ck[x][y] = 1
    for i in range(4):
        xx, yy = x + dx[i], y + dy[i]
        if grd[xx][yy] == 1 and ck[xx][yy] == 0:
            dfs(xx, yy)

def process():
    global grd, ck
    M, N, K = map(int, input().split())
    grd = [[0 for i in range(M + 2)] for j in range(N + 2)]
    ck = [[0 for i in range(M + 2)] for j in range(N + 2)]
    for _ in range(K):
        X, Y = map(int, input().split())
        grd[Y+1][X+1] = 1
    rst = 0
    for i in range(1, N+1):
        for j in range(1, M+1):
            if grd[i][j] == 1 and ck[i][j] == 0:
                dfs(i, j)
                rst += 1
    print(rst)

for _ in range(T):
    process()