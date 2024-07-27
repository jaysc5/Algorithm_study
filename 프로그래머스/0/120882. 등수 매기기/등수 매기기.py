def solution(score):
    avg = sorted([sum(s) for s in score], reverse = True)
    return [avg.index(sum(s))+1 for s in score]