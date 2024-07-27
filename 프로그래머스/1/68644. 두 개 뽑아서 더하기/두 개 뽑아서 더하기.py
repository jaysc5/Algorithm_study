from itertools import *

def solution(numbers):
    return sorted(set([a+b for [a, b] in combinations(numbers, 2)]))
