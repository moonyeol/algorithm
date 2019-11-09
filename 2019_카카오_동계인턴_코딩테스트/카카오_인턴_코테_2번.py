def solution(s):
    slist = s.replace("{{", "").replace("}}", "").split("},{")
    for i in range(len(slist)):
        slist[i] = list(map(int, slist[i].split(",")))
    answer = []

    temp = {}
    for i in range(len(slist)):
        temp[len(slist[i])] = slist[i]
    answer.append(temp[1][0])
    for i in range(1, len(slist)):
        for value in temp[i + 1]:
            if value not in temp[i]:
                answer.append(value)

    return answer



#정답 처리 되긴 됫지만 효율적으로 풀진 못한듯