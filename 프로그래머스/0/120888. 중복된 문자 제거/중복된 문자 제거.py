def solution(my_string):
    answer = ''

    for x in my_string:
        if x not in answer:
            answer += x
    
    return answer