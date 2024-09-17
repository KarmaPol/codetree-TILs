#include <iostream>
#include <algorithm>
using namespace std;

int n;

pair<int, int> times[100005];

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> times[i].second >> times[i].first;
    }

    sort(times, times+n);

    int time = 0, answer = 0;
    for(int i = 0; i < n; i++) {
        if(time > times[i].second) continue;

        // cout << times[i].second << ' ' << times[i].first << '\n';

        time = times[i].first;
        answer++;
    }

    cout << n - answer;

    return 0;
}