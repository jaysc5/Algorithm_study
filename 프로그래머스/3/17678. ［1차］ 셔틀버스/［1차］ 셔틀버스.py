def solution(n, t, m, timetable):
    answer = ''
    timetable = sorted([60*int(i[:2]) + int(i[3:]) for i in timetable])
    bustime = 540
    start = 540
    for i in range(n):
        for j in range(m):
            if timetable and timetable[0] <= bustime:
                start = timetable.pop(0) - 1
            else:
                start = bustime
        bustime += t
    
    answer = f'{str(start//60).zfill(2)}:{str(start%60).zfill(2)}'
    
    return answer