#include <iostream>

using namespace std;

int n;

int dp[1005][5][5];

const int MOD = 1e9 + 7;
int main() {
    cin >> n;

    dp[1][1][0] = 1;  // 첫 번째 날에 T를 받은 경우
    dp[1][0][1] = 1;  // 첫 번째 날에 B를 받은 경우
    dp[1][0][0] = 1;  // 첫 번째 날에 G를 받은 경우

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                // 다음 날로 넘어가는 경우의 수를 갱신합니다.
                dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + dp[i][j][k]) % MOD;
                dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][k]) % MOD;
                dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] + dp[i][j][k]) % MOD;
            }
        }
    }

    // 최종 결과를 계산합니다.
    int ans = 0;
    for(int j = 0; j < 3; j++) {
        for(int k = 0; k < 3; k++) {
            ans = (ans + dp[n][j][k]) % MOD;
        }
    }

    cout << ans;

    return 0;
}