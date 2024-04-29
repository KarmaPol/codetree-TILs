#include <iostream>

using namespace std;

int n, m;
pair<int,int> stones[105];
int dp[105][10005];

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        int w, v;
        cin >> w >> v;
        stones[i] = {w, v};
    }

    for(int i = 1; i <= n; i++) {
        int currentw = stones[i].first;
        int currentp = stones[i].second;

        for(int j = 1; j <= m; j++) {
            if(currentw <= j) {
                dp[i][j] = max(dp[i][j], dp[i][j-currentw] + currentp);
            }
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
        }
    }

    cout << dp[n][m];

    return 0;
}