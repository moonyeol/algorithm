#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int x, int y, int (*sudoku)[9]) {
	for (int i = 0; i < 9; i++) {
		if (sudoku[i][y] == sudoku[x][y] && i != x) {
			return false;
		}
		if (sudoku[x][i] == sudoku[x][y] && i != y) {
			return false;
		}

	}

	for (int i = 3 * (x / 3); i < 3 * (x / 3) + 3; i++) {
		for (int j = 3 * (y / 3); j < 3 * (y / 3) + 3; j++) {
			if (i == x && j == y)continue;
			if (sudoku[i][j] == sudoku[x][y]) {
				return false;
			}
		}
	}
	return true;
}


bool solve(int (*sudoku)[9], vector<pair<int,int>>& unVisited) {
	if (unVisited.size() == 0)
		return true;

	pair<int,int> temp = unVisited.back();
	int x = temp.first;
	int y = temp.second;
	unVisited.pop_back();
	for (int i = 1; i <= 9; i++) {
		sudoku[x][y] = i;
		if (check(x, y, sudoku)) {
			if (solve(sudoku, unVisited))
				return true;
		}
	}
	sudoku[x][y] = 0;
	unVisited.push_back(temp);
	return false;


}

int main() {
	int sudoku[9][9];
	vector<pair<int,int>> toFind;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j]==0) {
				pair<int,int> temp;
				temp.first = i;
				temp.second = j;
				toFind.push_back(temp);
			}
		}
	}
	solve(sudoku, toFind);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j] << " ";

		}
		cout << endl;
	}


	return 0;
}