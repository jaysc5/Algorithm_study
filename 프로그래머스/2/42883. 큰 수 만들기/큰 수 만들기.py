def solution(number, k):
    stack = []
    for num in number:
        if len(stack) == 0:
            stack.append(num)
            continue
        if k > 0:
            while stack[-1] < num:
                stack.pop()
                k -= 1
                if len(stack) == 0 or k <= 0:
                    break
        stack.append(num)
    stack = stack[:-k] if k > 0 else stack
    return ''.join(stack)