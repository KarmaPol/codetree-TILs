#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int map[55][55];
vector<pair<int,int>> hospitals;
vector<pair<int,int>> patients;
int minval = 2e9;

void makecombinations(int size, int idx, vector<int> temp) {
    if(temp.size() == size) {
        int totaldist = 0;
        for(auto i : temp) {
            auto current = hospitals[i];
            for(auto p : patients) {
                totaldist += abs(p.first - current.first) + abs(p.second - current.second);
            }
        }
        minval = min(minval, totaldist);
        return;
    }

    for(int i = idx; i < hospitals.size(); i++) {
        vector<int> copy = temp;
        copy.push_back(i);
        makecombinations(size, idx+1, copy);
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

    vector<int> v;
    makecombinations(m, 0, v);

    cout << minval;
    return 0;
}