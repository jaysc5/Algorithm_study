def solution(numbers):
    numbers = [str(x) for x in numbers]
    numbers.sort(key=lambda x : (x*4)[:4], reverse=True)
    if numbers[0] == '0':
        return '0'
    else:
        return ''.join(numbers)