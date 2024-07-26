import heapq
n = int(input())

lst = [int(input()) for _ in range(n)]

answer = 0
heapq.heapify(lst)

while len(lst) > 1:
    x = heapq.heappop(lst)
    y = heapq.heappop(lst)
    answer += x+y
    heapq.heappush(lst, x+y)

print(answer)