#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    map<int, int> map;

    while(n--){
        int x, y;
        cin >> x >> y;

        if(map.find(x) != map.end()) {
            map[x] = min(map[x], y);
        }
        else map[x] = y;
    }
    int sum = 0;
    for(auto pos : map) {
        sum += pos.second;
    }

    cout << sum;

    return 0;
}