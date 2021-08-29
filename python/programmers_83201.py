def get_person_grade(score):
    grade = "F"
    if score >= 90:
        grade = "A"
    elif 80 <= score < 90:
        grade = "B"
    elif 70 <= score < 80:
        grade = "C"
    elif 50 <= score < 70:
        grade = "D"
    return grade

def solution(scores):
    answer = ''
    lenScores = len(scores)
    newScores = list(map(list,zip(*scores)))
    for i in range(lenScores):
        lenThis = lenScores
        sumI = sum(newScores[i])
        if newScores[i].count(newScores[i][i]) <= 1:
            if max(newScores[i]) == newScores[i][i] or min(newScores[i]) == newScores[i][i]:
                sumI -= newScores[i][i]
                lenThis -= 1
        averageI = sumI/lenThis
        answer += get_person_grade(averageI)
    return answer