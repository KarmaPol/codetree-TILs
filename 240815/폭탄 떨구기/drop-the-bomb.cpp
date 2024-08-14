#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

int points[50005];

bool isPossible(int r) {
    int bombCount = 0;
    int bombRange = -1;

    for(int i = 0; i < n; i++) {
        int current = points[i];
        if(bombRange < current) {
            bombCount++;
            bombRange = current + 2*r;
        }
    }

    return bombCount <= k;
}

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> points[i];
    }

    sort(points, points + n);

    int left = 0, right = 1e9, mid;
    int answer = 2e9;

    while(left <= right) {
        mid = (left + right) / 2;

        if(isPossible(mid)) {
            answer = min(answer, mid);
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}