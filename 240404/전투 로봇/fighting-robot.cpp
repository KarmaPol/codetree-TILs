#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int,int>> monsters;
int map[25][25];
int visited[25][25];

int diry[4] = {-1, 0, 1, 0};
int dirx[4] = {0, -1, 0, 1};

pair<int,int> current;
pair<int,int> robot;

bool cmp(pair<int, int> a, pair<int, int> b) {
    int dista = abs(robot.first - a.first) + abs(robot.second - a.second);
    int distb = abs(robot.first - b.first) + abs(robot.second - b.second);
    if(dista == distb) {
        if(a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
    return dista > distb;
}

void resetvisited() {
    for(int i = 0; i < 25; i++) {
        for(int j = 0; j < 25; j++) {
            visited[i][j] = 0;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;

    cin >> n;

    queue<pair<int,int>> q;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 9) {
                robot = {i,j};
                q.push(robot);
                visited[i][j] = 1;
            }
            else if(map[i][j] > 0) {
                monsters.push_back({i,j});
            }
        }
    }

    int answer = 0;
    int level = 2, hunt = 2;
    vector<pair<int, int>> next;

    while(true) {
        while(!q.empty()) {
            current = q.front(); q.pop();

            if(map[current.first][current.second] != 0 && map[current.first][current.second] != 9
            && map[current.first][current.second] < level) {
                next.push_back(current);
                continue;
            }

            for(int i = 0; i < 4; i++) {
                int nexty = current.first + diry[i];
                int nextx = current.second + dirx[i];

                if(nexty < 0 || nexty >= n || nextx < 0 || nextx >= n) continue;
                if(map[nexty][nextx] > level) continue;
                if(visited[nexty][nextx] != 0) continue;

                visited[nexty][nextx] = visited[current.first][current.second] + 1;
                q.push({nexty, nextx});
            }
        }

        if(next.size() == 0) {
            break;
        }

        sort(next.begin(), next.end(), cmp);
        auto nextmonster = next[next.size() - 1];

        hunt--;
        if(hunt == 0) {
            level++;
            hunt = level;
        }
        map[nextmonster.first][nextmonster.second] = 0;
        map[robot.first][robot.second] = 0;
        robot = nextmonster;
        answer += visited[nextmonster.first][nextmonster.second] - 1;

        resetvisited();
        visited[nextmonster.first][nextmonster.second] = 1;
        q.push(nextmonster);
        next.clear();
    }

    cout << answer;

    return 0;
}