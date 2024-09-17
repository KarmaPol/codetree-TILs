#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int c, n;

pair<int, int> blacks[100005];

int main() {
    cin >> c >> n;

    set<int> reds;

    for(int i = 0; i < c; i++) {
        int red;
        cin >> red;

        reds.insert(red);
    }

    for(int i = 0; i < n; i++) {
        cin >> blacks[i].second >> blacks[i].first;
    }

    sort(blacks, blacks + n);

    int rIdx = 0, bIdx = 0, answer = 0;

    while(bIdx < n) {
        if(reds.lower_bound(blacks[bIdx].second) != reds.end()) {
            int red = *reds.lower_bound(blacks[bIdx].second);

            if(red <= blacks[bIdx].first) {
                answer++;
                reds.erase(red);
            }
        }   
        bIdx++;
    }

    cout << answer;

    return 0;
}