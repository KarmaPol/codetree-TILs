#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> numbers;
int dp[10005];

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    for(int i = 1; i <= m; i++) {
        dp[i] = 2e9;
    }

    for(int i = 0; i < n; i++) {
        for(int j = m; j >= 0; j--) {
            int currentnum = numbers[i];
            if(j < currentnum) continue;

            dp[j] = min(dp[j], dp[j - currentnum] + 1);
        }
    }

    if(dp[m] == 0) dp[m] = -1;
    cout << dp[m];

    return 0;
}