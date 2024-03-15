#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<pair<int,int>> hospitals;
vector<pair<int,int>> patients;
vector<int> selected;
int visited[15];
int totmin = 2e9;

void combinations(int size, int stage, int idx) {
    if(size == stage) {
        int tot = 0;
        for(auto p : patients) {
            int localmin = 2e9;
            for(auto i : selected) {
                auto h = hospitals[i];
                localmin = min(localmin, abs(h.first - p.first) + abs(h.second - p.second));
            }
            tot += localmin;
        }
        totmin = min(totmin, tot);
        return;
    }

    for(int i = idx; i < hospitals.size(); i++) {
        if(visited[i] == 1) continue;

        visited[i] = 1;
        selected.push_back(i);
        combinations(size, stage+1, i+1);
        visited[i] = 0;
        selected.pop_back();
    }
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

    combinations(m, 0, 0);

    cout << totmin;
    return 0;
}