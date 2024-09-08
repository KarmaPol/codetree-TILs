#include <iostream>
#include <algorithm>
using namespace std;

int n;

pair<int, int> bombs[10005];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return a.first > b.first;
    }

    return a.second < b.second;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> bombs[i].first >> bombs[i].second;
    }

    sort(bombs, bombs + n, cmp);

    int time = 0, total = 0;
    for(int i = 0; i < n; i++) {
        int currentTime = bombs[i].second;

        if(time >= currentTime) continue;

        total += bombs[i].first;
        time++;
    }

    cout << total;

    return 0;
}