import sys
sys.setrecursionlimit(100000)

def dfs(employee, accomplish ,boss):
    for i in employee[boss]:
        accomplish[i] += accomplish[boss]
        dfs(employee, accomplish, i)

n,m = map(int, sys.stdin.readline().rstrip().split())
employee = [[] for i in range(n+1)]
for index, value in enumerate(list(map(int, sys.stdin.readline().rstrip().split()))):
    if value == -1:
        continue
    employee[value].append(index+1)


accomplish = [0 for i in range(n+1)]

for j in range(m):
    i, w = map(int, sys.stdin.readline().rstrip().split())
    accomplish[i] += w

dfs(employee, accomplish, 1)

for j in accomplish[1:]:
    print(j,end=" ")