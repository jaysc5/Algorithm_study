def solution(n):
    answer = 0
    strarr = list(str(n))
    intarr = list(map(int, strarr))
    answer = sum(intarr)
    return answer