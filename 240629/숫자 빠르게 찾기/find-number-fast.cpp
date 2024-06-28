#include <iostream>

using namespace std;

int n, m;
int numbers[100005];

void bSearch(int target) {
    int left = 0, right = n-1, mid;
    
    while(left <= right) {
        mid = (left+right)/2;
        
        if(numbers[mid] == target) {
            cout << mid + 1 << '\n';
            return;
        }

        else if(numbers[mid] < target) {
            left = mid + 1;
        }
        
        else if(numbers[mid] > target) {
            right = mid - 1;
        }
    }

    cout << -1 << '\n';
    return;
}

int main() {

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;

        bSearch(num);
    }

    return 0;
}