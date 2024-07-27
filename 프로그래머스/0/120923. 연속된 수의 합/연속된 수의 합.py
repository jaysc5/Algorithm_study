def solution(num, total):
    answer = []
    avg = total // num
    
    for i in range(avg-(num-1)//2, avg+(num+2)//2):
        answer.append(i)
        
    return answer