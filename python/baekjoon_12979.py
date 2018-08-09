'''
백준 12979
종이접기
W×H 크기의 종이가 있다. 지금 현정이가 필요한 종이의 크기는 넓이가 A인 종이이다. 따라서, 종이를 접어서 넓이가 A인 종이를 만드려고 한다.

종이는 직선을 기준으로 접어야하며, 다음과 같은 두 가지 조건을 지켜야 한다.

종이를 접는 기준선은 직사각형의 한 변과 평행해야 한다.
종이를 접은 후에도 W와 H는 정수가 되어야 한다.
예를 들어, 5×3 크기의 종이가 있는 경우에, 너비를 기준으로 4가 되는 선으로 종이를 접으면 4×3 크기의 종이를 접게 된다. 이제, 높이를 기준으로 1이 되는 선을 기준으로 종이를 접어서 5×2 크기의 직사각형을 만들 수 있다.

W, H, A가 주어졌을 때, 넓이가 A가 되게 접을 수 있는지 없는지 구하고, 접을 수 있는 경우에는 접어야 하는 횟수의 최소값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 W, H, A가 주어진다. (1 ≤ W, H ≤ 1,000,000,000, 1 ≤ A ≤ 100,000)

출력
W×H 크기의 종이를 접어서 넓이가 A가 되게 만들 수 있으면 접는 횟수의 최소값을, 만들 수 없으면 -1을 출력한다.

'''


import math

def divisorGenerator(n):
    large_divisors = []
    for i in range(1, int(math.sqrt(n) + 1)):
        if n % i == 0:
            yield i
            if i * i != n:
                large_divisors.append(n // i)
    for divisor in reversed(large_divisors):
        yield divisor

def way(a, b) :
    if a == b :
        return 0
    elif a >= b/2  :
        return 1
    elif b%2 ==1 :
        return 1 + way(a, (b//2)+1)
    else :
        return 1 + way(a, b//2)

W, H, A = list(map(int,input().split()))

while not(W >=1 and H>=1 and W<=1000000000 and H<=1000000000and A<=100000and A>=1) :
    W, H, A = list(map(int, input().split()))
d = 2
a = []

if A ==1 :
    a.append(1)
    a.append(1)
else :
    a = list(divisorGenerator(A))
c = list(reversed(a))
b = list(zip(a,c))

mins = []

for i,j in  b:
    if i <= W and i <= H and j <= W and j <= H :
        if way(i,W) + way(j,H) < way(i,H) + way(j,W) :
            mins.append(way(i,W) + way(j,H))
        else :
            mins.append(way(i,H) + way(j,W))
    elif i <= W and j <= H:
        mins.append(way(i,W) + way(j,H))
    elif i <= H and j <= W:
        mins.append(way(i, H) + way(j, W))

if len(mins) == 0 :
    print(-1)
else :
    print(min(mins))