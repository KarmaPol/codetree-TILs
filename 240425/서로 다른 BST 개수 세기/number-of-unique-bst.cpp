#include <iostream>
#include <vector>

using namespace std;

vector<int> dp[25];

int main() {

    int n;
    cin >> n;

    dp[1].push_back(1);

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < dp[i-1].size(); j++) {
            for(int k = 1; k <= dp[i-1][j] + 1; k++) {
                dp[i].push_back(k);
            }
        }
    }

    cout << dp[n].size();

    return 0;
}