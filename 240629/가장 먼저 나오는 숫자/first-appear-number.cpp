#include <iostream>

using namespace std;

int n, m;
int numbers[100005];

void b_search(int target) {
    int left = 0, right = n-1, mid;

    int answer = 2e9;

    while(left <= right) {
        mid = (left+right)/2;

        if(numbers[mid] == target) {
            answer = min(answer, mid);
            right = mid - 1;
        }

        else if (numbers[mid] > target) {
            right = mid - 1;
        }
        else if (numbers[mid] < target) {
            left = mid + 1;
        }
    }

    if(answer != 2e9) {
        cout << answer + 1 << '\n';
        return;
    }
    cout << -1 << '\n';
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for(int i = 0; i < m; i++) {
        int number;
        cin >> number;
        b_search(number);
    }

    return 0;
}