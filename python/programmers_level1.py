def solution(n):
    n= list(str(n))
    new = []
    result = ''
    for i in n:
        new.append(int(i))
    new.sort(reverse=True)
    for i in new:
        result+=str(i)
    answer = int(result)
    return answer



def solution(participant, completion):
    answer = ''

    answer = list(set(participant)-set(completion))

    if len(answer) == 0:
        for i in participant:
            if i not in completion:
                answer = i
            else :
                completion.remove(i)
    else :
        answer = str(answer.pop())
    return answer