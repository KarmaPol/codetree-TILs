#include <iostream>
using namespace std;

int n, m;
int times[100005];

bool isPossible(int limit) {
    int currentLimit = 0;
    int lanesCount = 1;

    for(int i = 0; i < n; i++) {
        if(times[i] > limit) return false;

        currentLimit += times[i];
        if(currentLimit > limit) {
            currentLimit = times[i];
            lanesCount++;
        }
    }

    return lanesCount <= m;
}

int main() {

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> times[i];
    }

    int left = 1, right = 144000000, mid;
    int answer = 2e9;

    while(left <= right) {
        mid = (left + right) / 2;

        if(isPossible(mid)) {
            right = mid - 1;
            answer = min(mid, answer);
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}