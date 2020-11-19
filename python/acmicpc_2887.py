import collections
import sys
input=sys.stdin.readline


def find(parent,node):
    if parent[node] == node:
        return node;
    return find(parent,parent[node])

def union(parent, x, y):
    x = find(parent,x)
    y = find(parent,y)
    #작은 수를 부모로 삼음
    if x <y:
        parent[y] = x
        return x
    else:
        parent[x] = y
        return y

def findParent(parent, x,y):
    x = find(parent,x)
    y = find(parent,y)
    if x == y:
        return True
    else:
        return False

def kruskal(edges):
    result = 0
    for w, s, e in edges:
        if findParent(parent, s, e):
            continue
        else:
            result+= w
            union(parent, s, e)
    return result


N = int(input())
planets = []
edges = []
parent = [k for k in range(N)]
for i in range(N):
    x, y, z = map(int, input().split())
    planets.append((x,y,z,i))

for i in range(3):
    planets.sort(key = lambda x:x[i])
    pre = planets[0]
    for j in range(1,N):
        cur = planets[j]
        edges.append((abs(pre[i]-cur[i]),pre[3],cur[3]))
        pre =cur
edges.sort(key=lambda x:x[0])
ans =kruskal(edges)
print(ans)