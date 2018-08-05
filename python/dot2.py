# 내가 만든 문제(이미 있는 문제 일거 같다..)
# 두점 사이 거리가 가장 짧은 점 구하기
#
import math
dot = []
count = []

T = int(input())
for i in range(T):
    dot.append(list(map(int,input().split())))
min = (dot[0][0]-dot[1][0])**2+(dot[0][1]-dot[1][1])**2
for j in range(T-1):
    for i in range(j+1,T):
        if min > math.sqrt((dot[i][0]-dot[j][0])**2+(dot[i][1]-dot[j][1])**2) :
            min = math.sqrt((dot[i][0]-dot[j][0])**2+(dot[i][1]-dot[j][1])**2)
            count = [dot[j],dot[i]]
print(count)