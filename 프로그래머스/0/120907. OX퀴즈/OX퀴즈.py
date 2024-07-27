def solution(quiz):
    answer = []
    for q in quiz:
        x, y = q.split(' = ')
        if eval(x) == int(y):
            answer.append("O")
        else:
            answer.append("X")
    return answer