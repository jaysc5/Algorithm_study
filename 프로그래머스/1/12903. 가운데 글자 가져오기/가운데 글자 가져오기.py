def solution(s):
    answer = ''
    s_list = list(s)
    if len(s) % 2 == 0:
        answer = s[int(len(s)/2-1):int(len(s)/2+1)]
    else:
        answer = s[int((len(s)-1)/2)]
    return str(answer)