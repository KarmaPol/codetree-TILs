#include <iostream>

using namespace std;

int n, m;
pair<int, int> stones[105]; // 무게, 가치
int dp[10005];

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        int w, p;
        cin >> w >> p;
        stones[i] = {w, p};
    }

    for(int i = 0; i < n; i++) {
        int currentw = stones[i].first;
        int currentp = stones[i].second;
        for(int w = m; w > -1; w--) {
            if(currentw > w) continue;
            dp[w] = max(dp[w], dp[w - currentw] + currentp);
        }
    }
    
    int ans = 0;
    for(int j = 0; j <= m; j++){
        ans = max(ans, dp[j]);
    }

    cout << ans;

    return 0;
}