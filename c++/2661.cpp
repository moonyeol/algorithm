/*
���� 1, 2, 3���θ� �̷������ ������ �ִ�. ������ ������ ������ �� ���� �κ� ������ ������ ���� ������, �� ������ ���� �����̶�� �θ���. �׷��� ���� ������ ���� �����̴�.

������ ���� ������ ���̴�.

33
32121323
123123213
������ ���� ������ ���̴�.

2
32
32123
1232123
���̰� N�� ���� �������� N�ڸ��� ������ ���� ���� ���� ���� ���� ��Ÿ���� ������ ���ϴ� ���α׷��� �ۼ��϶�. ���� ���, 1213121�� 2123212�� ��� ���� ���������� �� �߿��� ���� ���� ��Ÿ���� ������ 1213121�̴�.

�Է�
�Է��� ���� N�ϳ��� �̷������. N�� 1 �̻� 80 �����̴�.

���
ù ��° �ٿ� 1, 2, 3���θ� �̷���� �ִ� ���̰� N�� ���� ������ �߿��� ���� ���� ���� ��Ÿ���� ������ ����Ѵ�. ������ �̷�� 1, 2, 3�� ���̿��� ��ĭ�� ���� �ʴ´�.

���� �Է� 1
7
���� ��� 1
1213121
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

#define MAX 51

using namespace std;

int len, maxValue;
bool visited[MAX];
vector<int> v;
string sIn;
bool dfs(int idx) {
	//if (v.size() > 50) return false;
	if (idx == len) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << " ";
			}
			cout << endl;
			return true;
	}

	int temp = sIn[idx] - '0';

	if (temp > 0) {
		if (!visited[temp]) {
			v.push_back(temp);
			visited[temp] = true;
			if (dfs(idx + 1)) return true;
			v.pop_back();
			visited[temp] = false;
		}
		if (idx < len -1) {
			temp *= 10;
			temp += sIn[idx + 1] - '0';
			if (temp <= maxValue && !visited[temp]) {
				v.push_back(temp);
				visited[temp] = true;
				if (dfs(idx + 2)) return true;
				v.pop_back();
				visited[temp] = false;
			}
		}
	}

	return false;
}

int main() {
	cin >> sIn;

	len = sIn.size();

	if (len > 9) {
		maxValue = 9 + ((len - 9) / 2);
	}
	else {
		maxValue = len;
	}

	dfs(0);

	return 0;	
}