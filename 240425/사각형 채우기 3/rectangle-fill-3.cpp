#include <iostream>

using namespace std;

int dp[1005];

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;

    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1]*2)%1000000007 + (dp[i-2]*3)%1000000007 + (dp[i-3]*2%1000000007)%1000000007;
        if(i > 3) {
            dp[i] += dp[i-4]*2 %1000000007;
        }
    }

    cout << dp[n];

    return 0;
}