# 다음 입사문제
# 1차원의 점들이 주어졌을 때, 그 중 가장 거리가 짧은 것의 쌍을 출력하는 함수를 작성하시오. (단 점들의 배열은 모두 정렬되어있다고 가정한다.)
# 예를들어 S={1, 3, 4, 8, 13, 17, 20} 이 주어졌다면, 결과값은 (3, 4)가 될 것이다.
# dot = list(map(int,input().split()))
# dot.sort()
# min = dot[-1]
# count = []
# for i in range(1,len(dot)) :
#     if min > dot[i]-dot[i-1] :
#         min = dot[i]-dot[i-1]
#         count = [dot[i-1],dot[i]]
# print(count)

# 두번째 방법
# inputList = [1,3,4,8,13,17,20]
# minVaule = max(inputList)
# index =0
# for i in range(len(inputList)-1):
#     if minVaule > abs(inputList[i]-inputList[i+1]):
#         minVaule = abs(inputList[i]-inputList[i+1])
#         index = inputList.index(inputList[i])
# print(index)
# print(inputList[index],inputList[index+1])
#
# 세번째 방법
# inputList = [1,3,4,8,13,17,20]
# pairs = list(zip(inputList[0:],inputList[1:]))
# print(list(pairs))
# pairs.sort(key=lambda x:abs(x[1]-x[0]))
# print(pairs[0])
#
# cal = [lambda x,y : x + y, lambda x,y : x -y]
# print(cal[0](3,5))
#
#
