def solution(my_string):
    tmp = 0
    my_string = my_string.split()
    answer = int(my_string[0])
    for my_str in my_string[::-1]:
        if my_str == '+':
            answer += tmp
        elif my_str == '-':
            answer -= tmp
        else:
            tmp = int(my_str)
    return answer