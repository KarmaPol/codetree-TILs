#include <iostream>
#include <cmath>
using namespace std;

int n;

int x[100005];
int v[100005];

bool isPossible(double target) { // 시간
    double left = x[0] - v[0] * target;
    double right = x[0] + v[0] * target;

    for(int i = 0; i < n; i++) {
        int currentx = x[i], currentv = v[i];
    
        double localright = currentx + target*currentv;
        double localleft = currentx - target*currentv;

        right = min(right, localright);
        left = max(left, localleft);
    }

    return left <= right;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    double left = 1, right = 1e9, mid;
    double answer = 1e9;

    for(int i = 1; i <= 100; i++) {
        double mid = (left + right) / 2;
        if(isPossible(mid)) {
            right = mid;
            answer = min(mid, answer);
        }
        else left = mid;
    }

    cout << fixed;
    cout.precision(4);

    cout << answer;

    return 0;
}