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
        dp[10005] = -1;
    }

    dp[0] = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < n; j++) {
            int currentcoin = coins[j];

            if(currentcoin > i) continue;
            if(dp[i - currentcoin] == -1) continue;
            dp[i] = max(dp[i], dp[i - currentcoin] + 1);
        }
    }

    // for(int i = 0; i <= m; i++) {
    //     cout << dp[i] << '\n';
    // }

    cout << dp[m];

    return 0;
}