#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<pair<int,int>> dist;
vector<pair<int,int>> hospitals;
vector<pair<int,int>> patients;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            if(temp == 2) {
                hospitals.push_back({i,j});
            } 
            else if (temp == 1) {
                patients.push_back({i,j});
            }
        }
    }

    for(int i = 0; i < hospitals.size(); i++) {
        auto h = hospitals[i];
        int tot = 0;
        for(auto p : patients) {
            tot += (abs(h.first - p.first) + abs(h.second - p.second));
        }
        dist.push_back({tot, i});
    }

    sort(dist.begin(), dist.end(), cmp);

    int answer = 0;
    for(int i = 0; i < m; i++) {
        answer += dist[i].first;
    }

    cout << answer;
    return 0;
}