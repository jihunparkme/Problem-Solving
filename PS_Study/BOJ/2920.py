a = [1, 2, 3, 4, 5, 6, 7, 8]
d = [8, 7, 6, 5, 4, 3, 2, 1]

A = list(map(int, input().split()))
if A == a: print('ascending')
elif A == d: print('descending')
else: print('mixed')