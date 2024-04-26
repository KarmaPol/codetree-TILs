#include <iostream>

using namespace std;

int n;

int map[105][105];
int dp[105][105];

void initdp() {
    dp[0][0] = map[0][0];

    for(int i = 1; i < n; i++) {
        dp[i][0] = max(map[i][0], dp[i-1][0]);
    }

    for(int j = 1; j < n; j++) {
        dp[0][j] = max(map[0][j], dp[0][j-1]);
    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = max(map[i][j], min(dp[i-1][j], dp[i][j-1]));
        }
    }

    cout << dp[n-1][n-1];

    return 0;
}