#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int treeMap[20][20];
pair<int, int> directions[105];
vector<pair<int,int> > drugs;

int dy[8] = {0,-1,-1,-1,0,1,1,1};
int dx[8] = {1,1,0,-1,-1,-1,0,1};

bool isDruged[20][20];

int n, m;

void moveDrugs(int d, int count) {
    for(int c = 0; c < count; c++) {
        for(int i = 0; i < drugs.size(); i++) {
            int curr_y, curr_x;
            tie(curr_y, curr_x) = drugs[i];

            int next_y = curr_y + dy[d], next_x = curr_x + dx[d];
            if(next_x < 0) {
                next_x += n;
            }
            if(next_x >= n) {
                next_x = next_x%n;
            }
            if(next_y < 0) {
                next_y += n;
            }
            if(next_y >= n) {
                next_y = next_y%n;
            }
            drugs[i] = {next_y, next_x};
        }
    }
}

void growTrees() {
    for(int i = 0; i < drugs.size(); i++) {
        int curr_y, curr_x;
        tie(curr_y, curr_x) = drugs[i];

        treeMap[curr_y][curr_x]++;
        isDruged[curr_y][curr_x] = true;
    }

    for(int i = 0; i < drugs.size(); i++) {
        int curr_y, curr_x;
        tie(curr_y, curr_x) = drugs[i];

        for(int d = 1; d < 8; d += 2) {
            int next_y = curr_y + dy[d];
            int next_x = curr_x + dx[d];

            if(next_y < 0 || next_y >= n || next_x < 0 || next_x >= n) continue;
            if(treeMap[next_y][next_x] == 0) continue;
            
            treeMap[curr_y][curr_x]++;
        }
    }
}

void deleteDrugs() {
    drugs.clear();
}

void resetIsDruged() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            isDruged[i][j] = false;
        }
    }
}

void cutTrees() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(isDruged[i][j]) continue;
            if(treeMap[i][j] < 2) continue;

            treeMap[i][j] -= 2;
            drugs.push_back({i, j});
        }
    }
}

void initDrugs() {
    drugs.push_back({n-2, 0});
    drugs.push_back({n-2, 1});
    drugs.push_back({n-1, 0});
    drugs.push_back({n-1, 1});
}

int getTotalTrees() {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans += treeMap[i][j];
        }
    }
    return ans;
}

void printTotalTrees() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << treeMap[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void printDrug() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int c = 0;
            for(int k = 0; k < drugs.size(); k++) {
                if(drugs[k].first == i && drugs[k].second == j) {
                    c = 1;
                    cout << "1 ";
                }
            }
            if(c == 0) cout << "0 ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> treeMap[i][j];
        }
    }
    initDrugs();

    for(int i = 0; i < m; i++) {
        int d, p;
        cin >> d >> p;
        directions[i] = {d-1, p};
    }

    for(int i = 0; i < m; i++) {
        moveDrugs(directions[i].first, directions[i].second);
        growTrees();
        deleteDrugs();
        cutTrees();
        resetIsDruged();
    }

    cout << getTotalTrees();

    return 0;
}