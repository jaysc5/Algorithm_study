def solution(citations):
    answer = 0
    citations.sort()
    n = len(citations)
    for i in range(n):
        hIndex = n - i

        if citations[i] >= hIndex:
            answer = hIndex
            break

    return answer