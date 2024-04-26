#include <iostream>

using namespace std;

int n;

int map[1005];
int dp[1005];

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> map[i];
        dp[i] = -1;
    }

    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) { 
            if(i > map[j] + j) continue;
            if(dp[j] == -1) continue;

            dp[i] = max(dp[j] + 1, dp[i]);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}