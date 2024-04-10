#include <iostream>
#include <tuple>
#include <queue>
#include <vector>

#define MAX_N 20
#define MAX_M 400
#define DIR_NUM 4
#define NOT_EXISTS make_pair(-1, -1)

using namespace std;

int n, m;

int grid[MAX_N + 1][MAX_N + 1];

vector<tuple<int,int,int,int> > passengers;
bool moved_passenger[MAX_M];

pair<int, int> car_pos;
int remaining_battery;

queue<pair<int,int> > bfs_q;
int step[MAX_N + 1][MAX_N + 1];
bool visited[MAX_N + 1][MAX_N + 1];

bool InRange(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

bool CanGo(int x, int y) {
    return InRange(x, y) && !visited[x][y] && !grid[x][y];
}

void InitializeVisited() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            visited[i][j] = false;
        }
    }
}

void BFS(pair<int,int> start_pos) {
    InitializeVisited();

    int start_x, start_y;
    tie(start_x, start_y) = start_pos;

    visited[start_x][start_y] = true;
    step[start_x][start_y] = 0;
    bfs_q.push({start_x, start_y});

    int dx[DIR_NUM] = {0, 1, 0, -1};
    int dy[DIR_NUM] = {1, 0, -1, 0};

    while(!bfs_q.empty()) {
        pair<int, int> curr_pos = bfs_q.front();
        int curr_x, curr_y;
        tie(curr_x, curr_y) = curr_pos;
        bfs_q.pop();

        for(int i = 0; i < DIR_NUM; i++) {
            int new_x = curr_x + dx[i];
            int new_y = curr_y + dy[i];

            if(CanGo(new_x, new_y)) {
                bfs_q.push({new_x, new_y});
                step[new_x][new_y] = step[curr_x][curr_y] + 1;
                visited[new_x][new_y] = true;
            }
        }
    }
}

bool NeedUpdate(pair<int, int> best_pos, pair<int, int> new_pos) {
    if(best_pos == NOT_EXISTS) return true;

    return make_tuple(step[best_pos.first][best_pos.second], best_pos.first, best_pos.second) >
        make_tuple(step[new_pos.first][new_pos.second], new_pos.first, new_pos.second);
}

bool MovePassenger() {
    BFS(car_pos);

    pair<int, int> best_pos = NOT_EXISTS;
    int best_index = -1;
    
    for(int i = 0; i < passengers.size(); i++) {
        int start_x, start_y, end_x, end_y;
        tie(start_x, start_y, end_x, end_y) = passengers[i];

        if(moved_passenger[i] ||
            !visited[start_x][start_y] ||
            step[start_x][start_y] > remaining_battery) continue;

        if(NeedUpdate(best_pos, {start_x, start_y})) {
            best_pos = {start_x, start_y};
            best_index = i;
        }
    }

    if(best_pos == NOT_EXISTS) return false;

    int start_x, start_y, end_x, end_y;
    tie(start_x, start_y, end_x, end_y) = passengers[best_index];
    
    car_pos = make_pair(start_x, start_y);
    remaining_battery -= step[start_x][start_y];

    BFS(make_pair(start_x, start_y));

    if(!visited[end_x][end_y] ||
    step[end_x][end_y] > remaining_battery) return false;

    car_pos = make_pair(end_x, end_y);
    remaining_battery -= step[end_x][end_y];

    moved_passenger[best_index] = true;
    remaining_battery += step[end_x][end_y] * 2;

    return true;
}

int main() {
    cin >> n >> m >> remaining_battery;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) 
            cin >> grid[i][j];
    
    int car_x, car_y;
    cin >> car_x >> car_y;
    car_pos = make_pair(car_x, car_y);
    
    for(int i = 1; i <= m; i++) {
        int start_x, start_y, end_x, end_y;
        cin >> start_x >> start_y >> end_x >> end_y;
        passengers.push_back(make_tuple(
            start_x, start_y, end_x, end_y
        ));
    }
    
    // m명의 승객을 전부 옮길 수 있는지를 판단합니다.
    for(int i = 1; i <= m; i++) {
        bool is_moved = MovePassenger();
        
        // 전부 옮기는 것이 불가능한 경우라면 -1을 출력하고
        // 프로그램을 종료합니다.
        if(!is_moved) {
            cout << -1;
            return 0;
        }
    }
    
    // 남아있는 배터리의 양을 출력합니다.
    cout << remaining_battery;
}