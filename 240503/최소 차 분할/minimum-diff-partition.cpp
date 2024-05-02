#include <iostream>

using namespace std;

int n;
int numbers[105];
int tot[105];
int dp[105];

int main() {
    cin >> n;

    for(int i = 1; i <= n ; i++) {
        cin >> numbers[i];
    }

    for(int i = 1; i <= n; i++) {
        tot[i] += tot[i-1] + numbers[i];

        dp[i] = min(abs(dp[i-1] - numbers[i]), abs(tot[i-1] - numbers[i]));
    }

    cout << dp[n];

    return 0;
}