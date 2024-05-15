#include <iostream>

using namespace std;

int n;
int stares[1005];
int dp[1005][4];

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> stares[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 4; j++) {
            if(j < 3 && dp[i-1][j] + stares[i] > dp[i][j+1]) {
                dp[i][j+1] = dp[i-1][j] + stares[i];
            }
            
            if(i >= 2 && dp[i-2][j] != 0 && dp[i-2][j] + stares[i] > dp[i][j]) {
                dp[i][j] = dp[i-2][j] + stares[i];
            }
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     int ans = -2e9;
    //     for(int j = 0; j < 4; j++) {
    //         ans = max(ans, dp[i][j]);
    //     }
    //     cout << ans << '\n';
    // }

    int ans = -2e9;
    for(int i = 0; i < 4; i++) {
        ans = max(ans, dp[n][i]);
    }

    cout << ans;

    return 0;
}