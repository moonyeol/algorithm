/*
���� ����
n���� �� ���̿� �ٸ��� �Ǽ��ϴ� ���(costs)�� �־��� ��, �ּ��� ������� ��� ���� ���� ���� �����ϵ��� ���� �� �ʿ��� �ּ� ����� return �ϵ��� solution�� �ϼ��ϼ���.

�ٸ��� ���� �� �ǳʴ���, ������ ���� ������ ���� �����ϴٰ� ���ϴ�. ���� ��� A ���� B �� ���̿� �ٸ��� �ְ�, B ���� C �� ���̿� �ٸ��� ������ A ���� C ���� ���� ���� �����մϴ�.

���ѻ���

���� ���� n�� 1 �̻� 100 �����Դϴ�.
costs�� ���̴� ((n-1) * n) / 2�����Դϴ�.
������ i�� ����, costs[i][0] �� costs[i] [1]���� �ٸ��� ����Ǵ� �� ���� ��ȣ�� ����ְ�, costs[i] [2]���� �� �� ���� �����ϴ� �ٸ��� �Ǽ��� �� ��� ����Դϴ�.
���� ������ �� �� �־����� �ʽ��ϴ�. ���� ������ �ٲ���� ���� ����� ���ϴ�. �� 0�� 1 ���̸� �����ϴ� ����� �־����� ��, 1�� 0�� ����� �־����� �ʽ��ϴ�.
��� �� ������ �ٸ� �Ǽ� ����� �־����� �ʽ��ϴ�. �� ���, �� �� ������ �Ǽ��� �Ұ����� ������ ���ϴ�.
������ �� ���� ���� �־����� �ʽ��ϴ�.
����� ��

n	costs	return
4	[[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]	4
����� �� ����

costs�� �׸����� ǥ���ϸ� ������ ������, �̶� �ʷϻ� ��η� �����ϴ� ���� ���� ���� ������� ��θ� ������ �� �ֵ��� ����� ����Դϴ�.
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// �θ��带 ������
int getParent(int* parent, int node) {
	if (parent[node] == node) {
		return node;
	}
	return getParent(parent, parent[node]);
}
// �� ����� �θ��带 ��ħ 
int unionParent(int* parent, int x, int y) {
	x = getParent(parent, x);
	y = getParent(parent, y);
	if (x < y) {
		parent[y] = x;
		return x;
	}
	else {
		parent[x] = y;
		return y;
	}
}
// ���� �θ��带 ������ Ȯ��
int findParent(int* parent, int x, int y) {
	x = getParent(parent, x);
	y = getParent(parent, y);
	if (x == y) { // ���� �θ� ���
		return 1;
	}
	else {
		// �ٸ� �θ� ���
		return 0;
	}
}

bool compare(const vector<int>& a, const vector<int>& b) {
	return a[2] < a[2];
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	std::sort(costs.begin(), costs.end(), compare);
	int* parent = new int[n];
	for (int i = 0; i < n; i++)
		parent[i] = i;

	for (int i = 0; i < costs.size(); i++) {
		if (!findParent(parent, costs[i][0], costs[i][1])) {
			answer += costs[i][2];
			unionParent(parent, costs[i][0], costs[i][1]);
		}
	}

	return answer;
}
