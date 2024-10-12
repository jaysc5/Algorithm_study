from collections import deque

def solution(cacheSize, cities):
    answer = 0
    l = [''] * cacheSize
    cache = deque(l, maxlen=cacheSize)
    
    for city in cities:
        city = city.lower()
        
        if city not in cache:
            cache.append(city)
            answer += 5
        else:
            cache.remove(city)
            cache.append(city)
            answer += 1
            
    return answer