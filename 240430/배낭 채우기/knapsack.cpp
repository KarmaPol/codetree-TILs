#include <iostream>

using namespace std;

int n, m;
pair<int, int> stones[105]; // 무게, 가치
int dp[105][10005];

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        int w, p;
        cin >> w >> p;
        stones[i] = {w, p};
    }

    for(int i = 1; i <= n; i++) {
        int currentw = stones[i].first;
        int currentp = stones[i].second;
        for(int j = 1; j <= m; j++) {
            if(currentw <= j) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-currentw] + currentp);
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m];

    return 0;
}