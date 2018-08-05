money = []

T=int(input())
for i in range(T) :
    a, b = map(int,input().split())
    money.append(0)
    if a > 0 :
        if a  <= 1 :
            money[i] += 5000000
        elif  a <=3 :
            money[i] += 3000000
        elif  a <=6 :
            money[i] += 2000000
        elif  a <= 10 :
            money[i] += 500000
        elif  a <= 15 :
            money[i] += 300000
        elif  a <= 21 :
            money[i] += 100000
    if b >0 :
        if b > 0 and b  <= 1 :
            money[i] += 5120000
        elif  b <=3 :
            money[i] += 2560000
        elif  b <=7 :
            money[i] += 1280000
        elif  b <= 15 :
            money[i] += 640000
        elif  b <= 31 :
            money[i] += 320000

for j in range(T) :
    print(money[j])
