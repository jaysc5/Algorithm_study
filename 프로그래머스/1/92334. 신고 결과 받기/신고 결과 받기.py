def solution(id_list, report, k):    
    report_uniq = dict.fromkeys(report)
    report_count = dict.fromkeys(id_list, 0)
    id_count = dict.fromkeys(id_list, 0)
    
    for rp in report_uniq:
        a, b = rp.split()
        report_count[b] += 1     
    report_count = {key: value for key, value in report_count.items() if value >= k } 
    
    for rp in report_uniq:
        a, b = rp.split()
        for rc in report_count:
            if rc == b:
                id_count[a] += 1
                
    return list(id_count.values())