#include <iostream>

using namespace std;

int weights[30];
int marbles[7];
bool visited[30][30 * 500 + 1];

void solution(int level, int num, int w_num) {
	if (level > w_num) return;
	if (visited[level][num]) return;

	visited[level][num] = true;

	solution(level + 1, num + weights[level], w_num);
	solution(level + 1, num, w_num);
	solution(level + 1, abs(num - weights[level]), w_num);
}


int main() {
	int w_num, m_num;
	cin >> w_num;
	for (int i = 0; i < w_num; i++) {
		cin >> weights[i];
	}
	cin >> m_num;
	for (int i = 0; i < m_num; i++) {
		cin >> marbles[i];
	}
	solution(0, 0, w_num);

	for (int i = 0; i < m_num; i++) {
		if (marbles[i] > 30 * 500) cout << "N ";
		else if (visited[w_num][marbles[i]]) cout << "Y ";
		else cout << "N ";
	}
	cout << endl;

	return 0;
}