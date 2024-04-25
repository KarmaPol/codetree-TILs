#include <iostream>

using namespace std;

int dp[105][105];
int map[105][105];

int n;

int dy[2] = {1, 0};
int dx[2] = {0, 1};

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i <= n; i++) {
        dp[0][i] = -2e9;
        dp[i][0] = -2e9;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int currenty = i, currentx = j;

            int prevmin = -2e9;
            for(int d = 0; d < 2; d++) {
                int prevy = currenty - dy[d];
                int prevx = currentx - dx[d];
                prevmin = max(dp[prevy][prevx], prevmin);
            }
            if(prevmin == -2e9) prevmin *= -1;

            prevmin = min(prevmin, map[currenty][currentx]);
            dp[currenty][currentx] = prevmin;
        }
    } 

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << dp[i][j];
    //     }
    //     cout << '\n';
    // }

    cout << dp[n][n];

    return 0;
}