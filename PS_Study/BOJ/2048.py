from copy import deepcopy

N = int(input())
Board = [list(map(int, input().split())) for _ in range(N)]

def Rotate(N, B):
    new_brd = deepcopy(B)
    for i in range(N):
        for j in range(N):
            new_brd[j][N-i-1] = B[i][j]
    return new_brd

def Combine(N, B):
    tmp = []
    for lst in B:
        new_lst = [i for i in lst if i]
        for i in range(1, len(new_lst)):
            if new_lst[i-1] == new_lst[i]:
                new_lst[i - 1] *= 2
                new_lst[i] = 0
        new_lst = [i for i in new_lst if i]
        tmp += [new_lst + [0] * (N - len(new_lst))]
    return tmp

def CombineLst(N, lst):
    new_lst = [i for i in lst if i]
    for i in range(1, len(new_lst)):
        if new_lst[i-1] == new_lst[i]:
            new_lst[i - 1] *= 2
            new_lst[i] = 0
    new_lst = [i for i in new_lst if i]
    return new_lst + [0] * (N - len(new_lst))


def DFS(N, B, cnt):
    rst = max([max(i) for i in B])
    if cnt == 0:
        return rst
    for _ in range(4):
        tmp = Combine(N, B)
        # tmp = [CombineLst(N, i) for i in B]
        if tmp != B:
            rst = max(rst, DFS(N, tmp, cnt-1))
        B = Rotate(N, B)
    return rst

print(DFS(N, Board, 5))