#include <iostream>

using namespace std;

int n;
int reds[205];
int blues[205];
int dp[205][105];

int main() {
    cin >> n;

    for(int i = 1; i <= 2*n; i++) {
        cin >> reds[i] >> blues[i];
    }

    for(int i = 1; i <= 2*n; i++) {
        for(int j = 0; j < i; j++) {
            dp[i][j+1] = max(dp[i-1][j] + reds[i], dp[i][j+1]);
            dp[i][j] = max(dp[i][j], dp[i-1][j] + blues[i]);
        }
    }

    // for(int i = 0; i <= 2*n; i++) {
    //     for(int j = 0; j <= n; j++) {
    //         cout << dp[i][j] << '\n';
    //     }
    //     cout << '\n';
    // }

    cout << dp[2*n][n];

    return 0;
}