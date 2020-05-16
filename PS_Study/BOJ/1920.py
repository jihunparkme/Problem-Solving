def binarySearch(N, A, key):
    lt, rt = 0, N-1

    while lt <= rt:
        mid = (lt + rt) / 2

        if A[mid] == key:
            return 1
        elif A[mid] > key:
            rt = mid - 1
        else:
            lt = mid + 1

    return 0

N = int(input())
A = list(map(int, input().split()))
M = input()
B = list(map(int, input().split()))

A.sort()

for n in B:
    res = binarySearch(N, A, n)
    print(res)