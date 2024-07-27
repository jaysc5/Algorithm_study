import heapq

def solution(n, works):
    heapq.heapify(works := [-i for i in works])

    for i in range(min(n, abs(sum(works)))):
        heapq.heappush(works, heapq.heappop(works)+1)
        
    return sum(w ** 2 for w in works)