#include <iostream>
#include <tuple>

using namespace std;

int n;

tuple<int, int, int> jobs[1005];
long long dp[1005];

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int s, e, p;
        cin >> s >> e >> p;
        jobs[i] = make_tuple(s, e, p);
    }

    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        int currents, currente, currentp;
        tie(currents, currente, currentp) = jobs[i];

        for(int j = 0; j < i; j++) {
            int prevs, preve, prevp;
            tie(prevs, preve, prevp) = jobs[j];

            if(preve >= currents) continue;

            dp[i] = max(dp[i], dp[j] + currentp);
        }
    }

    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}