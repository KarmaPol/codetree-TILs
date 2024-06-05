#include <iostream>

using namespace std;

int n, m;
int numbers[505];
int dp[105][255];

int main() {

    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = -2e9;
        }
    }

    for(int i = 1; i <= n; i++) {
        cin >> numbers[i];
        dp[i][0] = 0;
        dp[i][1] = numbers[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // 1개전까지의 구간합
            if(dp[i-1][j] != -2e9)
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            // 1개전까지의 구간합 + 현재 숫자
            if(dp[i-1][j] != -2e9)
                dp[i][j] = max(dp[i][j], dp[i-1][j] + numbers[i]);
            // 2개전의 구간합 + 현재 숫자
            if(i >= 2 && dp[i-2][j-1] != -2e9)
                dp[i][j] = max(dp[i][j], dp[i-2][j-1] + numbers[i]);
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << "i : " << i << '\n';
    //     for(int j = 1; j <= m; j++) {
    //         cout << dp[i][j] << '\n';
    //     }
    //     cout << '\n';
    // }

    cout << dp[n][m];

    return 0;
}