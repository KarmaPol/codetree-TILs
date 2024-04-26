#include <iostream>

using namespace std;

int n;
int dp[1010];

int main() {
    cin >> n;

    dp[5] = 1;
    for(int i = 1+5; i <= n+5; i++) {
        dp[i] = max(dp[i], dp[i-1] + dp[i-2] + dp[i-5]) % 10007;
    }
    cout << dp[n+5];

    return 0;
}