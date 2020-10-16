#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][1001];



int main() {
	int N, K;

	cin >> N;
	cin >> K;
	
	if (K == 1) {
		cout << N << endl;
		return 0;
	}
	else if (N < 2 * K) {
		cout << 0 << endl;
		return 0;
	}

	dp[1][1] = 1;
	dp[2][1] = 2;
	dp[3][1] = 3;

	for (int i = 4; i <= N; i++) {
		int limit = i / 2;
		for (int j = 1; j <= limit; j++) {
			if (j == 1) dp[i][j] = i;
			else dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % 1000000003;
		}
	}

	cout << dp[N][K] << endl;
	return 0;

}