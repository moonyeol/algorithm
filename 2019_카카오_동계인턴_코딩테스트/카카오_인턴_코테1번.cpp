#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int temp = 0;
	vector<int> basket;
	basket.push_back(-1);
	for (int i = 0; i < moves.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[j][moves[i] - 1]) {
				temp = board[j][moves[i] - 1];
				if (temp != basket.back()) {
					basket.push_back(temp);
				}
				else {
					basket.pop_back();
					answer += 2;
				}
				board[j][moves[i] - 1] = 0;
				break;
			}

		}
	}

	return answer;
}

//문제를 잘못이해해서 시간이 오래걸렸다