#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
pair<int, int> bombs[10005];

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int price, time;
        cin >> price >> time;
        bombs[i]= {time, price};
    }

    sort(bombs, bombs + n);

    priority_queue<int, vector<int>, less<int>> pq;
    int bomb_idx = n - 1;
    int total = 0;

    for(int i = 10000; i > 0; i--) {
        while(bomb_idx >= 0 && bombs[bomb_idx].first >= i) {
            pq.push(bombs[bomb_idx].second);
            bomb_idx--;
        }

        if(!pq.empty()) {
            total += pq.top(); pq.pop();
        }
    }

    cout << total;

    return 0;
}