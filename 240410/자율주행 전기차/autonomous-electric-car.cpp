#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[25][25];
int customerMap[25][25];
int customerDestMap[25][25];
int visited[25][25];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int n, m, c;

bool isAvailable(int nexty, int nextx) {
    return nexty >= 0 && nexty < n && nextx >= 0 && nextx < n;
}

bool isCustomer(int y, int x) {
    return customerMap[y][x] > 0;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(visited[a.first][a.second] == visited[b.first][b.second]) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    return visited[a.first][a.second] < visited[b.first][b.second];
}

pair<int,int> findCurrentCustomerDest(int p) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(customerDestMap[i][j] == -p) {
                return {i, j};
            }
        }
    }
    return {0, 0};
}

void resetVisited() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
}

void printVisited() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool isEnd() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(customerMap[i][j] != 0) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m >> c;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int y, x;
    cin >> y >> x;
    y--; x--;

    for(int i = 1; i <= m; i++) {
        int xs, ys, xe, ye;
        cin >> ys >> xs >> ye >> xe;
        customerMap[ys-1][xs-1] = i;
        customerDestMap[ye-1][xe-1] = -i;
    }

    queue<pair<int,int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    int answer = -1;

    while(!q.empty()) {
        vector<pair<int, int>> candidates;
        int useBattery = 0;
        // 손님 고르기
        while(!q.empty()) {
            pair<int,int> currentPosition = q.front();
            q.pop();

            if(isCustomer(currentPosition.first, currentPosition.second)) {
                candidates.push_back(currentPosition);
                continue;
            }

            for(int i = 0; i < 4; i++) {
                int nexty = currentPosition.first + dy[i];
                int nextx = currentPosition.second + dx[i];
                if(!isAvailable(nexty, nextx)) continue;
                if(visited[nexty][nextx] != 0) continue;
                if(map[nexty][nextx] == 1) continue;
                
                visited[nexty][nextx] = visited[currentPosition.first][currentPosition.second] + 1;
                q.push({nexty, nextx});
            }
        }
        // 손님 없으면 종료
        if(candidates.size() == 0) {
            if(isEnd()) answer = c;
            break;
        }

        // 손님 정렬 & 손님, 목적지 설정
        sort(candidates.begin(), candidates.end(), cmp);
        pair<int, int> currentCustomerPosition = candidates[0];
        c -= visited[currentCustomerPosition.first][currentCustomerPosition.second] - 1;
        int currentCustomerNum = customerMap[currentCustomerPosition.first][currentCustomerPosition.second];
        pair<int, int> currentCustomerDest = findCurrentCustomerDest(currentCustomerNum);
        while(!q.empty()) q.pop();
        q.push(currentCustomerPosition); 
        resetVisited(); visited[currentCustomerPosition.first][currentCustomerPosition.second] = 1;

        // 목적지로 출발
        while(!q.empty()) {
            pair<int,int> currentPosition = q.front();
            q.pop();

            if(currentPosition.first == currentCustomerDest.first && currentPosition.second == currentCustomerDest.second) {
                useBattery += visited[currentPosition.first][currentPosition.second] - 1;
                while(!q.empty()) q.pop();
                break;
            }

            for(int i = 0; i < 4; i++) {
                int nexty = currentPosition.first + dy[i];
                int nextx = currentPosition.second + dx[i];
                if(!isAvailable(nexty, nextx)) continue;
                if(visited[nexty][nextx] != 0) continue;
                if(map[nexty][nextx] == 1) continue;
                
                visited[nexty][nextx] = visited[currentPosition.first][currentPosition.second] + 1;
                q.push({nexty, nextx});
            }
        }
        // 배터리 소진되지 않고 도착했는지 검사
        if(useBattery == 0 || useBattery > c) {
            continue;
        }
        c += useBattery;
        q.push(currentCustomerDest);
        resetVisited(); visited[currentCustomerDest.first][currentCustomerDest.second] = 1;
        customerMap[currentCustomerPosition.first][currentCustomerPosition.second] = 0;
    }

    cout << answer;

    return 0;
}