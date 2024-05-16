#include <iostream>

using namespace std;

int n, k;

int numbers[100005];
int dp[100005][15];

int main() {

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> numbers[i];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++) {
            dp[i][j] = -2e9;
        }
    }

    dp[0][0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            if(numbers[i+1] < 0 && j < k) {
                if(dp[i][j] != -2e9) 
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + numbers[i+1]);
            } 
            else if(numbers[i+1] >= 0) {
                if(dp[i][j] != -2e9)
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j] + numbers[i+1]);
            }

            if(numbers[i+1] < 0)
                dp[i+1][1] = max(dp[i+1][1], numbers[i+1]);
            else {
                dp[i+1][0] = max(dp[i+1][0], numbers[i+1]);
            }
        }
    }

    int ans = -2e9;
    for(int j = 1; j <= n; j++) {
        for(int i = 0; i <= k; i++) {
            ans = max(ans, dp[j][i]);
        }
    }
    cout << ans;

    return 0;
}