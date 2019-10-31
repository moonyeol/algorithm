'''문제 설명
체스의 새로운 말 공작을 다음과 같이 정의한다: 1 칸을 위, 아래, 왼쪽, 오른쪽으로 움직일 수 있다.

공작은 n x n 보드의 string initPosition에 놓여 있다. 이 문제에서는 열은 왼쪽에서 오른쪽으로 'a', 'b', 등으로 표시되고 행은 아래에서 위로 '1', '2', 등으로 표시된다. 칸은 "cr" (따옴표 제외)로 표기되며, 이 때, c는 행이고 r은 열이다.

공작 말이 움직인 칸을 대시 기호로 구분하여 표현해보자. 예를 들어, "c5-b5-b4"는 두번의 움직임으로 만든 경로이다. 첫번째로 왼쪽으로 한칸 움직였고 (c5-b5) 그 다음에 한칸 아래로 움직였다 (b5-b4). 동일한 칸을 두번 이상 방문하지 않은 경로를 간단하다고 말한다.

string initPosition에서 출발하여 공작이 이동할 수 있는 사전순으로 가장 큰 간단한 경로를 반환하여라. 만약 경로의 길이가 40 글자를 넘는다면 처음 20개의 글자와 마지막의 20개의 글자를 세개의 점으로 분류하여 반환하여라 (예제 2번 참조).

참고 / 제약 사항
문자열 A와 문자열 B가 있을 때, B가 A의 접두사이거나 A와 B의 글자가 처음으로 다른 지점에서 A의 글자가 B보다 클 때, A가 B보다 사전적으로 크다고 한다.
n은 2 이상, 8 이하이다.
initPosition은 오직 2개의 글자만을 가진다.
initPosition의 첫번째 글자는 'a'와 'h' 사이의 소문자이다.
initPosition의 두번째 글자는 '1'과 '8'사이의 숫자이다.
initPosition은 n x n 보드 안에 존재하는 칸을 나타낸다.
테스트 케이스
int n = 3
string initPosition = "b2"리턴(정답): "b2-c2-c3-b3-a3-a2-a1-b1-c1"
오른쪽으로 가장 먼저 이동하고 나서, 보드 둘레를 시계반대방향으로 이동한다.

int n = 4
string initPosition = "d4"리턴(정답): "d4-d3-d2-d1-c1-c2-c3...b3-b2-b1-a1-a2-a3-a4"
아래쪽으로 세번 이동하고 왼쪽으로 이동하여 위로 세번 이동하고 다시 왼쪽으로 이동하는 등의 동작을 반복한다. 사전적으로 가장 큰 경로는 47글자이므로 중간 부분은 "..."으로 대체되었다.

int n = 3
string initPosition = "a2"리턴(정답): "a2-b2-c2-c3-b3-a3"


int n = 4
string initPosition = "d3"리턴(정답): "d3-d4-c4-c3-c2-d2-d1...b2-b3-b4-a4-a3-a2-a1"


int n = 5
string initPosition = "a4"리턴(정답): "a4-b4-c4-d4-e4-e5-d5-c5-b5-a5"'''


# 핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution:
    def read(self,position):
        tmp = list(position)
        a = {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5, 'f': 6, 'g': 7, 'h': 8}
        i = a[tmp[0]]
        return i, int(tmp[1])


    def write(self,num1, num2):
        i = {1: 'a',
             2: 'b',
             3: 'c',
             4: 'd',
             5: 'e',
             6: 'f',
             7: 'g',
             8: 'h'
             }.get(num1)
        return i + str(num2)

    def solution(self, n, initPosition):
        mat = [[0 for i in range(n+2)] for j in range(n+2)]



        for i in range(0,n+2):
            mat[0][i] = 1
            mat[-1][i] = 1
            mat[i][0] = 1
            mat[i][-1] = 1
        i, j = self.read(initPosition)
        mat[i][j] = 1
        strings = ""
        strings += initPosition

        while (True):
            if mat[i + 1][j] == 0:
                i += 1
                mat[i][j] = 1
                strings += "-" + self.write(i, j)
            elif mat[i][j + 1] == 0:
                j += 1
                mat[i][j] = 1
                strings += "-" + self.write(i, j)
            elif mat[i][j - 1] == 0:
                j -= 1
                mat[i][j] = 1
                strings += "-" + self.write(i, j)
            elif mat[i - 1][j] == 0:
                i -= 1
                mat[i][j] = 1
                strings += "-" + self.write(i, j)
            else:
                break

        if len(strings) >= 40:
            strings = strings[:20] + "..." + strings[-20:]
        return strings


a = Solution()
print(a.solution(5,"a4"))