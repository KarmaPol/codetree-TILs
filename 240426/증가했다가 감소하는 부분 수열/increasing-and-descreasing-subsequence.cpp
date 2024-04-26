#include <iostream>

using namespace std;

int n;

int map[1005];
int dpNotDecrease[1005];
int dpDecrease[1005];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> map[i];
        dpNotDecrease[i] = 1;
        dpDecrease[i] = -1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(map[i] > map[j]) {
                dpNotDecrease[i] = max(dpNotDecrease[i], dpNotDecrease[j] + 1);
            } 
            else if(map[i] < map[j]) {
                // 첫 감소
                dpDecrease[i] = max(dpDecrease[i], dpNotDecrease[j] + 1);
                // 쭉 감소
                dpDecrease[i] = max(dpDecrease[i], dpDecrease[j] + 1);
            }
        } 
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, dpDecrease[i]);

    cout << ans;

    return 0;
}