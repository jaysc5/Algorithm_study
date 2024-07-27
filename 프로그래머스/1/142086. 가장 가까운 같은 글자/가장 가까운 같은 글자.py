def solution(s):
    answer = []
    dic = {}
    for i, st in enumerate(s):
        if st not in dic:
            answer.append(-1)
        else:
            answer.append(i - dic[st])
        dic[st] = i
    return answer