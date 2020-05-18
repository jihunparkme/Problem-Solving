N, r, c = map(int, input().split())

def Solution(sz, x, y):
    if sz == 1:
        return 0
    sz //= 2
    for i in range(2):
        for j in range(2):
            if x < sz * (i+1) and y < sz * (j+1):
                return (i*2+j) * sz * sz + Solution(sz, x - sz * i, y - sz * j)

print(Solution(2**N, r, c))