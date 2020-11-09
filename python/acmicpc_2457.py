import datetime
import sys
input=sys.stdin.readline


ans =0
N = int(input())
flowers = []
for i in range(N):
    flowers.append(list(map(int,input().split())))

flowers.sort(key=lambda x:(x[0],x[1],-x[2],-x[3]))

YEAR = 2019
d = datetime.datetime(YEAR,3,1)
endd = datetime.datetime(YEAR,11,30)
ans = 0
maxd = d
i = 0

#print(flowers)
while d <= endd:
    flag = False
    for j in range(i,len(flowers)):
        sM, sD, eM, eD = flowers[j]
        sd = datetime.datetime(YEAR,sM,sD)
        ed = datetime.datetime(YEAR,eM,eD)
        if sd == ed:
            continue
        if sd <= d:
            if ed > maxd:
                maxd = ed
                i = j +1
        else:
            if maxd < sd:
                flag = True
            break
    if flag:
        ans = 0
        break
    d = maxd
    ans +=1
    if i >= N:
        if d <= endd:
            ans = 0
        break

print(ans)