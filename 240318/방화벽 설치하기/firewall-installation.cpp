#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int diry[4] = {1, 0, -1, 0};
int dirx[4] = {0, 1, 0, -1};
int map[10][10];
int visited[10][10];

int n, m;

vector<vector<pair<int, int>>> combinations;
vector<pair<int,int>> combination;
vector<pair<int,int>> temp;
int selected[100];

void getcmb(int idx) {
    if(combination.size() == 3) {
        combinations.push_back(combination);
    }

    for(int i = idx; i < temp.size(); i++) {
        if(selected[i]) continue;

        selected[i] = 1;
        combination.push_back(temp[i]);
        getcmb(idx+1);
        selected[i] = 0;
        combination.pop_back();
    }
}

void resetvistied() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            visited[i][j] = 0;
        }
    }
}

int countnotfire() {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0 && visited[i][j] != 2) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;

    queue<pair<int, int>> q;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                q.push({i, j});
                visited[i][j] = 1;
            }
            if(map[i][j] == 0) {
                temp.push_back({i,j});
            }
        }
    }

    getcmb(0);

    int maxnotfire = -2e9;

    for(auto c : combinations) {
        queue<pair<int, int>> copyq = q;
        resetvistied();

        while(!copyq.empty()) {
            auto current = copyq.front();
            copyq.pop();

            for(int i = 0; i < 4; i++) {
                int nexty = current.first + diry[i];
                int nextx = current.second + dirx[i];

                if(nexty < 0 || nexty >= n || nextx < 0 || nextx >= m) continue;
                if(map[nexty][nextx]) continue;
                if(nexty == c[0].first && nextx == c[0].second) continue;
                if(nexty == c[1].first && nextx == c[1].second) continue;
                if(nexty == c[2].first && nextx == c[2].second) continue;
                if(visited[nexty][nextx]) continue;

                visited[nexty][nextx] = 2;
                copyq.push({nexty, nextx});
            }
        }
        for(auto walls : c) {
            visited[walls.first][walls.second] = 2;
        }

        maxnotfire = max(maxnotfire, countnotfire());
    }

    cout << maxnotfire;

    return 0;
}