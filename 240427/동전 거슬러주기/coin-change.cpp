#include <iostream>

using namespace std;

int n, m;
int coins[105];
int dp[10005];

int main() {

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    for(int i = 0; i <= m; i++) {
        dp[i] = 2e9;
    }

    dp[0] = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < n; j++) {
            int currentcoin = coins[j];
            if(i < currentcoin) continue;

            dp[i] = min(dp[i], dp[i-currentcoin] + 1);
        }
    }

    int ans = dp[m];
    if(ans == 2e9) ans = -1;
    cout << ans;

    return 0;
}