#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n, m;

int map[105][105];
int visited[105][105];

int dy[4] = {1, 0, -1 ,0};
int dx[4] = {0, 1 ,0, -1};

void initVisited() {
    for(int i =0; i< n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
}

void bfs(int lo, int hi) {
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0][0] = 1;

    while(!q.empty()) {
        pair<int, int> current = q.front(); q.pop();
        int currenty = current.first, currentx = current.second;

        for(int i = 0; i < 4; i++) {
            int nexty = currenty + dy[i];
            int nextx = currentx + dx[i];

            if(nexty < 0 || nexty >= n || nextx < 0 || nextx >= m) continue;
            if(visited[nexty][nextx]) continue;
            if(map[nexty][nextx] < lo || map[nexty][nextx] > hi) continue;
            visited[nexty][nextx] = 1;

            q.push({nexty, nextx});
        }
    }
}

bool isPossible(int limit) {
    for(int h = 1; h <= 500; h++) {
        initVisited();

        int hmax = h + limit;
        if(map[0][0] < h || map[0][0] > hmax) continue;

        bfs(h, hmax);
        
        if(visited[n-1][m-1]) return true;
    }

    return false;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int left = 0, right = 500, mid;
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

// 핵심은 h의 최소를 반복문 돌리고, 최대를 이분탐색으로 찾는것