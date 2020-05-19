N = int(input())
map = [list(map(int, input().split())) for _ in range(N)]
dx, dy = [0, -1, 1, 0, 0], [0, 0, 0, -1, 1]
mmax = 1000000000
res = mmax

def solve(lst):
    res = 0
    flower = []
    for pos in lst:
        x = pos // N
        y = pos % N

        if x == 0 or x == N-1 or y == 0 or y == N-1: return mmax

        for c in range(5):
            xx, yy = x + dx[c], y + dy[c]
            flower.append((xx, yy))
            res += map[xx][yy]

    if len(set(flower)) == 15: return res
    else: return mmax

for i in range(N*N):
    for j in range(i+1, N * N):
        for k in range(j+1, N * N):
            res = min(res, solve([i, j, k]))

print(res)