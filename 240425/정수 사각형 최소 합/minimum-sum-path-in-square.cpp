#include <iostream>
#include <vector>

using namespace std;

int n;

int map[105][105];
int dp[105][105];

int dy[2] = {1, 0};
int dx[2] = {0, -1};

int main() {

    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        dp[i][n+1] = 1e9;
        dp[0][i] = 1e9;
    }
    dp[0][n] = 0;
    dp[1][n+1] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = n; j > 0; j--) {
            int currenty = i, currentx = j;
            
            int minsum = 2e9;
            for(int d = 0; d < 2; d++) {
                int prevy = currenty - dy[d];
                int prevx = currentx - dx[d];

                minsum = min(dp[prevy][prevx] + map[currenty][currentx], minsum);
            }
            dp[currenty][currentx] = minsum;
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[n][1];
    
    return 0;
}