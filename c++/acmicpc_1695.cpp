#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[5001][5001];
int arr[5001];


int solution(int a, int b) {
	if (dp[a][b] != -1) return dp[a][b];
	if (a >= b) {
		dp[a][b] = 0;
		return dp[a][b];
	}
	if (arr[a] == arr[b]) dp[a][b] = solution(a + 1, b - 1);
	else dp[a][b] = min(solution(a, b - 1), solution(a + 1, b)) + 1;
	return dp[a][b];

}

int main() {
	int N,temp;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1;
		}
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			solution(i, j);
		}
	}

	cout << dp[0][N - 1];

	return 0;

}