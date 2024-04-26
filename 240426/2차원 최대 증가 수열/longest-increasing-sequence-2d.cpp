#include <iostream>

using namespace std;

int n, m;
int map[55][55];
int dp[55][55];

int main() {

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            int currenty = i, currentx = j;

            for(int t = i+1; t < n; t++) {
                for(int k = j+1; k < m; k++) {
                    int nexty = t, nextx = k;
                    if(map[nexty][nextx] <= map[currenty][currentx]) continue;
                    if(dp[currenty][currentx] == -1) continue;
                    dp[nexty][nextx] = max(dp[nexty][nextx], dp[currenty][currentx] + 1);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;

    return 0;
}