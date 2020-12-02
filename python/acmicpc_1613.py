import sys
import heapq

input = sys.stdin.readline

INF = float('inf')

def floydWashall(historys,n):
    for i in range(1,n+1):
        for j in range(1,n+1):
            for k in range(1,n+1):
                if historys[j][i] and historys[i][k]:
                    historys[j][k] = 1


n, k = map(int, input().split())
historys = [[0 for _ in range(n+1)] for _ in range(n+1)]

quiz = []
for i in range(k):
    a,b = map(int, input().split())
    historys[a][b] =1
s = int(input())
for i in range(s):
    quiz.append(list(map(int,input().split())))
floydWashall(historys,n)

for a,b in quiz:
    if historys[a][b]:
        print(-1)
    elif historys[b][a]:
        print(1)
    else:
        print(0)