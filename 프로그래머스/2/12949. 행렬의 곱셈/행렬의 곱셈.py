def solution(arr1, arr2):
    return [[sum(a*b for a, b in zip(a_row, b_col)) for b_col in zip(*arr2)] for a_row in arr1]