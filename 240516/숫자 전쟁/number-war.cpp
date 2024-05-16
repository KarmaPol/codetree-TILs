#include <iostream>

using namespace std;

int n;
int a[1005], b[1005];
int dp[1005][1005];

int main() {

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dp[i][j] == -1) continue;

            // 카드 대결 - 첫 번째 플레이어의 카드가 더 작은 경우
            if(a[i + 1] < b[j + 1])
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

            // 카드 대결 - 두 번째 플레이어의 카드가 더 작은 경우
            if(a[i + 1] > b[j + 1])
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + b[j + 1]);

            // 카드 버리기
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
        }
    }

    int ans = -2e9;
    for(int i = 0; i <= n; i++) {
        ans = max(ans, dp[i][n]);
        ans = max(ans, dp[n][i]);
    }

    cout << ans;

    return 0;
}