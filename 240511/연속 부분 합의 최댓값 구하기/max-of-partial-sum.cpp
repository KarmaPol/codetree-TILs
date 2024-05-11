#include <iostream>

#define INF_MIN -2e9

using namespace std;

int numbers[100005];
int dp[100005];

int n;

int main() {
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> numbers[i];
    }

    for(int i = 0; i <= n; i++) {
        dp[i] = INF_MIN;
    }

    for(int i = 1; i <= n; i++) {
        dp[i] = max(dp[i-1] + numbers[i], numbers[i]);
    }

    int ans = INF_MIN;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}