def solution(lottos, win_nums):
    cnt_corr = 0
    cnt_zero = lottos.count(0)
    rank = [6,6,5,4,3,2,1]
    
    for lotto in lottos:
        if lotto in win_nums:
            cnt_corr += 1
        
    return [rank[cnt_corr + cnt_zero],rank[cnt_corr]]