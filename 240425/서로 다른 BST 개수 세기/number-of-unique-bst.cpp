#include <iostream>
#include <vector>

using namespace std;

vector<int> dp[25];

int main() {

    int n;
    cin >> n;

    dp[2].push_back(1);
    dp[2].push_back(2);

    for(int i = 3; i < n; i++) {
        for(int j = 0; j < dp[i].size(); i++) {
            for(int k = 1; k <= dp[i][j] + 1; k++) {
                dp[i].push_back(k);
            }
        }
    }

    cout << dp[n].size();

    return 0;
}