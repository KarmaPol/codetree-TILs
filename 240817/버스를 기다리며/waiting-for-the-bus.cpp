#include <iostream>
#include <algorithm>
using namespace std;

int n, m ,c;
int members[100005];

bool isPossible(int target) {
    int busCount = 1, userCount = 1;
    int last = members[0];

    for(int i = 1; i < n; i++) {
        int current = members[i];
        userCount++;

        if(userCount > c) {
            last = current;
            busCount++;
            userCount = 1;
        }

        if(current - last > target) {
            last = current;
            busCount++;
        }
    }

    return m >= busCount;
}

int main() {
    cin >> n >> m >> c;

    for(int i = 0; i < n; i++) {
        cin >> members[i];
    }

    sort(members, members + n);

    int left = 0, right = 1e9, mid;
    int answer = 1e9;

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