#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

vector<pair<int,int>> lines;
int dp[1005]; // 선분 개수

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        lines.push_back({start, end});
        dp[i] = 1;
    }
    
    sort(lines.begin(), lines.end());

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(lines[i].first <= lines[j].second) continue;
            
            dp[i] = max(dp[j]+1, dp[i]);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}