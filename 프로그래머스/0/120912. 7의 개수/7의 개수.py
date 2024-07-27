def solution(array):
    answer = 0
    for arr in array:
        answer += str(arr).count("7")

    print(str(array))
    return answer