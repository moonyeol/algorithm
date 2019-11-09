#include <string>
#include <vector>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	vector<bool> dict(k + 1, true);
	long long temp = room_number[0];
	int j = 0;
	while (true) {
		if (dict[temp]) {
			answer.push_back(temp);
			dict[temp] = false;
			j += 1;
			if (j == room_number.size()) break;
			temp = room_number[j];
		}
		else temp++;
	}
	return answer;
}
//탐색 알고리즘을 고치면 효율성테스트도 통과했을거 같은데
//알고리즘 공부한지 조금 기간이 있다보니 기억이 안나서 못풀었다
//문제는 맞게 풀긴했다, 효율성테스트에서 오답처리됫다