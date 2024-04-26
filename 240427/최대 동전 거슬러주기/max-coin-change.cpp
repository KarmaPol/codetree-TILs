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

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < n; j++) {
            int currentcoin = coins[j];

            if(currentcoin > i) continue;
            dp[i] = max(dp[i], dp[i - currentcoin] + 1);
        }
    }

    if(dp[m] == 0) dp[m] = -1;    
    cout << dp[m];

    return 0;
}