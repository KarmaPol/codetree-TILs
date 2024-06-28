#include <iostream>

using namespace std;

int n, m;

int numbers[100005];

int lb_search(int target) {
    int left = 0, right = n-1, mid;

    int lb = n;

    while(left <= right) {
        mid = (left+right)/2;

        if(numbers[mid] == target) {
            lb = min(lb, mid);
            right = mid - 1;
        }
        else if(numbers[mid] >= target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return lb;
}

int ub_search(int target) {
    int left = 0, right = n-1, mid;

    int ub = n;

    while(left <= right) {
        mid = (left+right)/2;

        if(numbers[mid] > target) {
            ub = min(ub, mid);
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return ub;
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for(int i = 0; i < m; i++) {
        int number;
        cin >> number;

        int count = ub_search(number) - lb_search(number);
        if(count < 0) {
            count = 0;
        }
        cout << count << '\n';
    }

    return 0;
}