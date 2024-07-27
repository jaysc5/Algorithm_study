def solution(clothes):
    answer = 1
    types = [y for x, y in clothes]
    counts = [types.count(type) for type in set(types)]

    for c in counts:
        answer *= c + 1
    return answer - 1