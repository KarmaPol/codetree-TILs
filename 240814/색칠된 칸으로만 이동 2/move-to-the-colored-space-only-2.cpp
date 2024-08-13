#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int m, n;
int map[105][105];
int colored[105][105];
int tempColored[105][105];
int visited[105][105];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void copyColored() {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            tempColored[i][j] = colored[i][j];
        }
    }
}

bool isAllColorPassed() {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(tempColored[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

void bfs(int starty, int startx, int d) {
    queue<pair<int, int>> q;

    q.push({starty, startx});
    visited[starty][startx] = 1;
    tempColored[starty][startx]--;

    while(!q.empty()) {
        pair<int,int> current = q.front(); q.pop();
        int currenty = current.first, currentx = current.second;

        for(int i = 0; i < 4; i++) {
            int nexty = currenty + dy[i], nextx = currentx + dx[i];
            
            if(nexty < 0 || nexty >= m || nextx < 0 || nextx >= n) continue;
            if(visited[nexty][nextx]) continue;
            if(abs(map[currenty][currentx] - map[nexty][nextx]) > d) continue;

            visited[nexty][nextx] = 1; tempColored[nexty][nextx]--;
            q.push({nexty, nextx});
        }
    }
}

void initVisited() {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
}

bool isPossible(int target) {
    initVisited(); copyColored();
    int starty = -1, startx = -1;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j] == 0 && tempColored[i][j] == 1) {
                starty = i, startx = j;
                break;
            }
        }
        if(starty != -1) break;
    }

    bfs(starty, startx, target);

    return isAllColorPassed();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> colored[i][j];
        }
    }

    int left = 0, right = 1e9, mid;
    int answer = 2e9;

    while(left <= right) {
        mid = (left + right)/2;

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