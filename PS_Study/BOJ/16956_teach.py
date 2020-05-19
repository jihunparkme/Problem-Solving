R, C = map(int, input().split())
map = [list(input()) for _ in range(R)]

dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

ck = False

for i in range(R):
    for j in range(C):
        if map[i][j] == 'W':
            for w in range(4):
                ii, jj = i + dx[w], j + dy[w]
                if ii < 0 or ii == R or jj < 0 or jj == C: continue
                if map[ii][jj] == 'S': ck = True

if ck: print(0)
else:
    print(1)
    for i in range(R):
        for j in range(C):
            if map[i][j] not in 'SW':
                map[i][j] = 'D'
    for i in map:
        print(''.join(i))