#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n, m;

int map[105][105];
pair<int, int> visited[105][105];

int dy[4] = {1, 0, -1 ,0};
int dx[4] = {0, 1 ,0, -1};

void printVisited() {
    for(int i =0; i< n; i++) {
        for(int j = 0; j < m; j++) {
            cout << abs(visited[i][j].first- visited[i][j].second) << '\n';
        }
    }
}

void initVisited() {
    for(int i =0; i< n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = {1000, -1000};
        }
    }
}

void bfs(int limit) {
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0][0] = {map[0][0], map[0][0]};

    while(!q.empty()) {
        pair<int, int> current = q.front(); q.pop();
        int currenty = current.first, currentx = current.second;

        for(int i = 0; i < 4; i++) {
            int nexty = currenty + dy[i];
            int nextx = currentx + dx[i];

            if(nexty < 0 || nexty >= n || nextx < 0 || nextx >= m) continue;
            int nextMin = min(visited[currenty][currentx].first, map[nexty][nextx]);
            int nextMax = max(visited[currenty][currentx].second, map[nexty][nextx]);

            if(abs(nextMax - nextMin) >= abs(visited[nexty][nextx].first - visited[nexty][nextx].second)) continue;
            if(abs(nextMax - nextMin) > limit) continue;
            // cout << currenty << ':' << currentx << "->" << nexty << ':' << nextx << " " << nextMax << ':' << nextMin << "  " << abs(nextMax - nextMin) << '\n';

            visited[nexty][nextx].first = nextMin; visited[nexty][nextx].second = nextMax; 

            q.push({nexty, nextx});
        }
    }
}

bool isPossible(int limit) {
    initVisited();
    // cout << "current: " << limit << '\n';

    bfs(limit);
    // printVisited();

    return abs(visited[n-1][m-1].first - visited[n-1][m-1].second) <= limit;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int left = 1, right = 500, mid;
    int answer = 500;

    while(left <= right) {
        mid = (left + right) / 2;
        if(isPossible(mid)) {
            answer = min(answer, mid);
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}