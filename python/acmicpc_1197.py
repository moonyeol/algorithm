import heapq
INF = float('inf')

def getParent(parent,node):
    if parent[node] == node:
        return node;
    return getParent(parent,parent[node])

def union(parent, x, y):
    x = getParent(parent,x)
    y = getParent(parent,y)
    #작은 수를 부모로 삼음
    if x <y:
        parent[y] = x
        return x
    else:
        parent[x] = y
        return y

def findParent(parent, x,y):
    x = getParent(parent,x)
    y = getParent(parent,y)
    if x == y:
        return True
    else:
        return False






edges = []
V, E = map(int,input().split())
for j in range(E):
    edges.append(list(map(int, input().split())))


answer = 0
sorted_edge = sorted(edges,key=lambda x:x[2])
parent = [k for k in range(V+1)]
for j in sorted_edge:
    if not findParent(parent,j[0],j[1]):
        union(parent,j[0],j[1])
        answer += j[2]
print(answer)

