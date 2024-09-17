#include <algorithm>
#include <iostream>
using namespace std;

int c, n;

int reds[100005];
pair<int, int> blacks[100005];

int main() {
    cin >> c >> n;

    for(int i = 0; i < c; i++) {
        cin >> reds[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> blacks[i].first >> blacks[i].second;
    }

    sort(reds, reds + n);
    sort(blacks, blacks + n);

    int rIdx = 0, bIdx = 0, answer = 0;

    while(rIdx < c && bIdx < n) {
        if(reds[rIdx] < blacks[bIdx].first) {
            rIdx++;
            continue;
        }   
        
        if(reds[rIdx] > blacks[bIdx].second) {
            bIdx++;
            continue;
        }

        answer++;
        rIdx++; bIdx++;
    }

    cout << answer;

    return 0;
}