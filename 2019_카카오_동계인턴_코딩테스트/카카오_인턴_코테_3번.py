def solution(user_id, banned_id):
    answer = 0
    dict = {}
    dict2 = {}
    index = []
    breakbool = False
    for i in user_id:
        if len(i) in dict:
            dict[len(i)].append(i)
        else:
            dict[len(i)] = []
            dict[len(i)].append(i)
    for i in banned_id:
        if len(i) in dict2:
            dict2[len(i)].append(i)
        else:
            dict2[len(i)] = []
            dict2[len(i)].append(i)
    for i in banned_id:
        for j in dict[len(i)]:
            index.append(i.find('*'))
            if i[:index[-1]] != j[:index[-1]]:
                while index[-1] < len(i):
                    index.append(i.find('*', index[-1]))
                    if index[-1] == -1:
                        break
                    if i[index[-2] + 1:index[-1]] != j[index[-2] + 1:index[-1]]:
                        breakbool = True
            if breakbool:
                break
            answer += 1
            dict[len(i)].remove(j)
            index = []

    return answer

#도저히 푸는 방법이 생각안나서 3중루프 썻는데 역시 오답이다