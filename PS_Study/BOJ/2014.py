import heapq
import copy

K, N = map(int, input().split())
p_lst = list(map(int, input().split()))

lst, ck = copy.deepcopy(p_lst), set()

heapq.heapify(lst)
ith = 0

while ith < N:
    mn = heapq.heappop(lst)
    if mn in ck:
        continue
    ith += 1
    ck.add(mn)
    for i in p_lst:
        if mn * i < 2 ** 32:
            heapq.heappush(lst, mn*i)
    print(lst)
print(mn)