def solution(n):
    answer = 0
    s = str(n)
    my_list = list(s)
    my_list.sort()
    my_list.reverse()
    answer = ''.join(s for s in my_list)
    answer = int(answer)
    return answer