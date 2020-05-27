from copy import deepcopy
dx, dy = [1, 0, -1, 0], [0, -1, 0, 1]

N, M, K = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
Q = [tuple(map(int, input().split())) for _ in range(K)]

rst = 10000

def MinVal(arr):
    return min([sum(lst) for lst in arr])

def Rotate(arr, qry):
    (r, c, s) = qry
    r, c = r-1, c-1
    new_arr = deepcopy(arr)
    for i in range(1, s+1):
        rr, cc = r-i, c+i
        for w in range(4):
            for d in range(i*2):
                rrr, ccc = rr + dx[w], cc + dy[w]
                new_arr[rrr][ccc] = arr[rr][cc]
                rr, cc = rrr, ccc
    return new_arr

def DFS(arr, qry):
    global rst
    if sum(qry) == K:
        rst = min(rst, MinVal(arr))
        return
    for i in range(K):
        if qry[i]:
            continue
        new_arr = Rotate(arr, Q[i])
        qry[i] = 1
        DFS(new_arr, qry)
        qry[i] = 0

DFS(A, [0 for i in range(K)])
print(rst)