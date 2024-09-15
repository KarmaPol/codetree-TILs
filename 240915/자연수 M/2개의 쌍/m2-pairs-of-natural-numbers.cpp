#include <iostream>
#include <queue>
using namespace std;

int n;

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> greaterq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> lessq;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int count, number;

        cin >> count >> number;
        greaterq.push({number, count}); lessq.push({number, count});
    }

    int answer = -2e9;
    while(!greaterq.empty() && !lessq.empty()) {
        pair<int, int> currentg = greaterq.top(); greaterq.pop();
        pair<int, int> currentl = lessq.top(); lessq.pop();

        answer = max(answer, currentg.first + currentl.first);

        if(currentg.second != 1) {
            greaterq.push({currentg.first, currentg.second - 1});
        }
        if(currentl.second != 1) {
            lessq.push({currentl.first, currentl.second - 1});
        }
    }

    cout << answer;
        

    return 0;
}