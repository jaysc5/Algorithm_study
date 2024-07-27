def solution(arr1, arr2):
    answer = []
    for arr1, arr2 in zip(arr1, arr2):
        answer.append([i+j for i,j in zip(arr1, arr2)])
    return answer