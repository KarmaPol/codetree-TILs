#include <iostream>

#define INT_MAX 2e9

using namespace std;

int n;
int num[105][105];
int dp[105][105][105];

void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < 105; k++) {
                dp[i][j][k] = INT_MAX;
            }
        }
    }

    dp[0][0][num[0][0]] = num[0][0];

    for(int i = 1; i < n; i++) {
        for(int k = 1; k < 105; k++) {
            dp[i][0][min(k, num[i][0])] = min(
                dp[i][0][min(k, num[i][0])],
                max(dp[i-1][0][k], num[i][0])
            );
        }
    }

    for(int j = 1; j < n; j++) {
        for(int k = 1; k < 105; k++) {
            dp[0][j][min(k, num[0][j])] = min(
                dp[0][j][min(k, num[0][j])],
                max(dp[0][j-1][k], num[0][j])
            );
        }
    }
}

void solve() {
    init();

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            for(int k = 1; k < 105; k++) {
                dp[i][j][min(k, num[i][j])] = min(
                    dp[i][j][min(k, num[i][j])],
                    max(min(dp[i-1][j][k], dp[i][j-1][k]), num[i][j])
                );
            }
        }
    }
}

int main() {

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> num[i][j];
    
    solve();

    int ans = INT_MAX;
    for(int k = 1; k < 105; k++) {
        if(dp[n-1][n-1][k] != INT_MAX)
            ans = min(ans, dp[n-1][n-1][k] - k);
    }

    cout << ans;
    return 0;
}