import math

def solution(fees, records):
    answer = []
    bt, bf, ut, uf = fees
    parking = dict()
    stack = dict()
    
    for r in records:
        time, car, inout = r.split()
        h, m = time.split(':')
        time = int(h) * 60 + int(m)
        
        if inout == 'IN':
            parking[car] = time
        elif inout == 'OUT':
            if car in stack:
                stack[car] += time - parking.get(car)
            else:
                stack[car] = time - parking.get(car)
            del parking[car] 
            
            
    for car, time in parking.items():
        if car in stack:
            stack[car] += 23*60+59 - time
        else:
            stack[car] = 23*60+59 - time

    stack = sorted(stack.items())
            
    for car, time in stack:
        if time <= bt:
            answer.append(bf)
        else:
            answer.append(bf + math.ceil((time - bt) / ut ) * uf)        

    return answer