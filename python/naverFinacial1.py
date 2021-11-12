def solution(id_list, k):
    answer = 0
    couponDict = {}
    for ids in id_list:
        dailySet = set()
        for id in ids:
            if id == ' ':
                pass
            else:
                dailySet.add(id)
        for id in dailySet:
            if id in couponDict:
                couponDict[id] += 1
            else:
                couponDict[id] = 1
    for i in list(couponDict.values()):
        answer += i
    return answer