#include <iostream>

using namespace std;

int n, m;
int numbers[505];
int dp[505][300][2];

int main() {

    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k < 2; k++) 
                dp[i][j][k] = -2e9;
        }
    }

    for(int i = 1; i <= n; i++) {
        cin >> numbers[i];
        dp[i][0][0] = 0;
        dp[i][0][1] = 0;
        dp[i][1][1] = numbers[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // 1개전까지의 구간합, 현재 숫자는 포함하지 않는다
            if(dp[i-1][j][0] != -2e9)
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0]);
            if(dp[i-1][j][1] != -2e9)
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][1]);
            // 1개전까지의 구간합 + 현재 숫자
            if(dp[i-1][j-1][0] != -2e9)
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][0] + numbers[i]);
            // 1개전까지의 구간합 + 현재 숫자
            if(dp[i-1][j-1][1] != -2e9)
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1] + numbers[i]);
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << "i : " << i << '\n';
    //     for(int j = 1; j <= m; j++) {
    //         for(int k = 0; k < 2; k++)
    //             cout << dp[i][j][k] << '\n';
    //     }
    //     cout << '\n';
    // }

    cout << max(dp[n][m][0], dp[n][m][1]);

    return 0;
}