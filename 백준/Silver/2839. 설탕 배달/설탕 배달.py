sugar = int(input())
bag = 0

while sugar >= 0:
    if sugar % 5 == 0:
        bag += sugar // 5
        break
    else:
        bag += 1
        sugar -= 3
else:
    bag = -1
    
print(bag)