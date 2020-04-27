def dfs(banned, index, tmp=set(), lists=[]):
    if index == len(banned):
        if tmp not in lists:
            lists.append(tmp)
        return
    for i in banned[index]:
        if i not in tmp:
            dfs(banned, index + 1, tmp | set([i]), lists)
    return len(lists)


def solution(user_id, banned_id):
    lists = []
    answer = 0
    num = 0
    for i in banned_id:
        tmp = []
        for j in user_id:
            if len(i) == len(j):
                for k in range(len(i)):
                    if (i[k] != j[k]) & (i[k] != '*'):
                        break
                else:
                    tmp.append(j)
        lists.append(tmp)

    answer = dfs(lists, 0)

    return answer