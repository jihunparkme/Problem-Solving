dx, dy = [0, -1, 0, 1], [1, 0, -1, 0]
N, K = map(int, input().split())
grd = [list(input()) for _ in range(N)]
ck, ck2 = [], []

def reset():
    return [[0 for j in range(10)] for i in range(N)]

def DFS(x, y):
    global grd, ck
    ck[x][y] = 1
    cnt = 1

    for i in range(4):
        xx, yy = x + dx[i], y + dy[i]
        if xx < 0 or xx >= N or yy < 0 or yy >= 10:
            continue
        if ck[xx][yy] or grd[xx][yy] != grd[x][y]:
            continue
        cnt += DFS(xx, yy)

    return cnt

def DFSZ(x, y, clr):
    global grd, ck2
    ck2[x][y] = 1
    grd[x][y] = '0'

    for i in range(4):
        xx, yy = x + dx[i], y + dy[i]
        if xx < 0 or xx >= N or yy < 0 or yy >= 10:
            continue
        if ck2[xx][yy] or grd[xx][yy] != clr:
            continue
        DFSZ(xx, yy, clr)

def Down():
    global grd
    while True:
        exist = False

        for x in range(N-2, -1, -1):
            for y in range(10):
                if grd[x][y] != '0' and grd[x+1][y] == '0':
                    grd[x + 1][y], grd[x][y] = grd[x][y], '0'
                    exist = True

        if not exist:
            break

while True:
    exist = False
    ck, ck2 = reset(), reset()

    for x in range(N):
        for y in range(10):
            if grd[x][y] != '0' and not ck[x][y]:
                cnt = DFS(x, y) # 탐색
                if cnt >= K:
                    exist = True
                    DFSZ(x, y, grd[x][y]) # 0으로 수정

    if not exist:
        break
    Down() # 하강

for i in grd:
    print(''.join(i))