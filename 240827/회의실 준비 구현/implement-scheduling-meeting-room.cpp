#include <iostream>
#include <algorithm>
using namespace std;

int n;

pair<int,int> meetings[100005];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }

    sort(meetings, meetings + n, cmp);

    int answer = 0;
    int lastUsedTime = 0;
    for(int i = 0; i < n; i++) {
        pair<int, int> currentMeeting = meetings[i];
       if(lastUsedTime > currentMeeting.first) {
            continue;
       } 
       lastUsedTime = currentMeeting.second;
       answer++;
    }

    cout << answer;

    return 0;
}