#include <iostream>

using namespace std;

int n;

int numbers[1005];
int dp[1005];

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
        dp[i] = 1;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(numbers[i] > numbers[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i]);

    cout << ans;

    return 0;
}