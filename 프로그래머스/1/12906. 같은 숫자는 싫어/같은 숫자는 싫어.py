def solution(arr):
    answer = []
    
    answer.append(arr[0])
    for i in range(1,len(arr)):
        answer.append(arr[i])
        if arr[i-1] == arr[i]:
            answer.pop()
            
    return answer