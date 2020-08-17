#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

bool check(string& answer) {
	for (int i = 1; i <= answer.length() / 2; i++) {
		string back = answer.substr(answer.length() - i, i);
		string front = answer.substr(answer.length() - i*2, i);
		if (front == back) {
			answer.erase(answer.length() - 1);
			return false;
		}
	}
	return true;
}

bool dfs(int now_level,int max_level,string &answer) {
	if (now_level >= max_level) return true;
	bool chk = false;
	bool chk2 = false;
	for (int i = 1; i <= 3; i++) {
		chk = check(answer.append(to_string(i)));
		if (chk) {
			chk2 = dfs(now_level + 1, max_level, answer);
			if (chk2) {
				return true;
			}
			
		}
	}
	answer.erase(answer.length() - 1);
	return false;
}

int main() {
	int num;
	cin >> num;
	string answer = "";
	if (num == 1) {
		answer.append("1");
	}
	else if (num == 2) {
		answer.append("1");
		answer.append("2");
	}
	else if (num >= 3) {
		answer.append("1");
		answer.append("2");
		answer.append("1");
		dfs(3, num, answer);
	}


		cout << answer;
}