def solution(n):
    answer = []
    while True:
        answer.append(n)
        if n==1:
            return answer
        n = n/2 if n%2==0 else n*3+1
    return answer