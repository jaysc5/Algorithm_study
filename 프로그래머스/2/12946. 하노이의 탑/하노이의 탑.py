def hanoi(n, src, sub, dst, answer):
    if n == 1:
        answer.append([src, dst])
    else:
        hanoi(n-1, src, dst, sub, answer)
        hanoi(1, src, sub, dst, answer)
        hanoi(n-1, sub, src, dst, answer)
    return answer
    
def solution(n):
    return hanoi(n, 1, 2, 3, [])