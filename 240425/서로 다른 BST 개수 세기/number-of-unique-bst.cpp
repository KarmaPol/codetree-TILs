#include <iostream>
#include <vector>

using namespace std;

int dp[25];

int main() {

    int n;
    cin >> n;

    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            dp[i] += dp[j] + 1;
        }
    }

    cout << dp[n];

    return 0;
}