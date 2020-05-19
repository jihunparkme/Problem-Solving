dx, dy = [0, -1, 0, 1], [1, 0, -1, 0]

def Solution():
    for x in range(R):
        for y in range(C):
            if map[x][y] == 'W':
                for i in range(4):
                    xx, yy = x + dx[i], y + dy[i]

                    if xx < 0 or yy < 0 or xx >= R or yy >= C:
                        continue

                    if map[xx][yy] == 'S':
                        print('0')
                        return

    print(1)
    for r in range(R):
         print(''.join(map[r]))
    return

R, C = map(int, input().split())
map = [input().replace('.', 'D') for _ in range(R)]

Solution()