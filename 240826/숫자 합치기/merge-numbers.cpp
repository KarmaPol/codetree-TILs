#include <iostream>
#include <queue>
using namespace std;

int n;

int main() {
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        int number;
        cin >> number;
        
        pq.push(number);
    }

    int price = 0;
    while(pq.size() > 1) {
        int smallest1 = pq.top(); pq.pop();
        int smallest2 = pq.top(); pq.pop();
        
        pq.push(smallest1 + smallest2);
        price += smallest1 + smallest2;
    }

    cout << price;

    return 0;
}