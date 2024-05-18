#include <iostream>

using namespace std;

int n;

int dp[1005][3][3];

int MOD = 1e9+7;

int main() {
    cin >> n;

    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    dp[1][0][1] = 1;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + dp[i][j][k]) % MOD;
                dp[i + 1][j][0] = (dp[i+1][j][0] + dp[i][j][k]) % MOD;
                dp[i+1][j][k+1] = (dp[i+1][j][k+1] + dp[i][j][k]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            ans += dp[n][i][j];
        }
    }

    cout << ans;

    return 0;
}