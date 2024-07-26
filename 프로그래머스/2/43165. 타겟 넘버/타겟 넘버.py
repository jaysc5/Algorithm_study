answer = 0

def dfs(numbers, target, index, result):
    global answer
    if index == len(numbers):
        if result == target:
            answer += 1
        return
    
    for i in [-1, +1]:
        dfs(numbers, target, index+1, result + i * numbers[index])

def solution(numbers, target):
    dfs(numbers, target, 0, 0)
    return answer