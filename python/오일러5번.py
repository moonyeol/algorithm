# 1 ~ 10 사이의 어떤 수로도 나누어 떨어지는 가장 작은 수는 2520입니다.
# 그러면 1 ~ 20 사이의 어떤 수로도 나누어 떨어지는 가장 작은 수는 얼마입니까?
num = 2
gcd = 1
time =1
while num <= 20 :
    if gcd * time % num ==0:
        gcd *= time
        time =1
        num += 1
    else :
        time += 1
print(gcd)