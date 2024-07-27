def solution(chicken):
    answer = 0
    while chicken >= 10:
        coupon_1 = int(chicken / 10)
        coupon_2 = chicken % 10
        answer += coupon_1
        chicken = coupon_1 + coupon_2
    return answer