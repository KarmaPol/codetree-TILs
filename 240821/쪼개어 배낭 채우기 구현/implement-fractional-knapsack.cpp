#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

pair<double,double> jewels[100005];

bool cmp(pair<double, double> a, pair<double, double> b) {
    return a.second / a.first > b.second / b.first;
}

int main() {

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> jewels[i].first >> jewels[i].second;
    }
    sort(jewels, jewels + n, cmp);
    
    double totPrice = 0;

    int idx = 0;
    while(m > 0) {
        double currentPrice = jewels[idx].second, currentWeight = jewels[idx].first;

        if(m >= currentWeight) {
            totPrice += currentPrice;
            m -= currentWeight;
        }
        else {
            totPrice += m * (currentPrice/currentWeight);
            m -= m;
        }
        idx++;
    }

    cout << fixed;
    cout.precision(3);

    cout << totPrice;

    return 0;
}