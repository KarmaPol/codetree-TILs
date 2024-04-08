#include <iostream>
#include <vector>

using namespace std;

int map[15][15]; // 색 표기
vector<pair<int, int>> horses[15][15]; // <말 번호, 방향>
pair<int, int> horsePositions[15];

int diry[4] = {0, 0, -1, 1};
int dirx[4] = {1, -1, 0, 0};

int n, k;

void getinputs() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    int x, y, d;
    for(int i = 0; i < k; i++) {
        cin >> x >> y >> d;
        horses[x-1][y-1].push_back({i, d-1});
        horsePositions[i] = {x-1,y-1};
    }
}

pair<int, int> getNextPosition(int dir, pair<int, int> current) {
    pair<int, int> next = {current.first + diry[dir], current.second + dirx[dir]};\
    return next;
}

bool inRange(pair<int, int> next) {
    return next.first >= 0 && next.first < n && next.second >= 0 && next.second < n;
}

int convertNotRangeDirection(int dir) {
    if(dir == 0) dir = 1;
    else if(dir == 1) dir = 0;
    else if(dir == 2) dir = 3;
    else if(dir == 3) dir = 2;

    return dir;
}

pair<int, int> convertNotRangePostion(pair<int, int> next) {
    if(next.first < 0) {
        next.first *= -1;
    }
    if(next.first >= n) {
        next.second = n-2;
    }
    if(next.second < 0) {
        next.second *= -1;
    }
    if(next.second >= n) {
        next.second = n-2;
    }

    return next;
}

void moveHorse(pair<int, int> nextPos, vector<pair<int, int>> nexthorses) {
    for(int i = 0; i < nexthorses.size(); i++) {
        horses[nextPos.first][nextPos.second].push_back({nexthorses[i].first, nexthorses[i].second});
    }
}

void refreshHorsePositions() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            auto currentHorses = horses[i][j];
            // cout << i << ' ' << j << '\n';
            for(auto ch: currentHorses) {
                // cout << ch.first << '\n';
                horsePositions[ch.first] = {i, j};
            }
        }
    }
    // cout << '\n';
}

bool simulate() {
    for(int i = 0; i < k; i++) {
        pair<int,int> currentposition = horsePositions[i];
        vector<pair<int,int>> currenttile = horses[currentposition.first][currentposition.second];
        vector<pair<int,int>> nexthorses;
        bool isCurrent = false;
        int idx = -1;
        
        // 다음에 움직일 말들 추리기
        for(int j = 0; j < currenttile.size(); j++) {
            if(currenttile[j].first == i) {
                isCurrent = true; idx = j;
            }
            if(!isCurrent) continue;
            nexthorses.push_back(currenttile[j]);
        }

        // 추린 말들은 제거
        cout << idx << '\n';
        horses[currentposition.first][currentposition.second].erase(
            horses[currentposition.first][currentposition.second].begin() + idx,
            horses[currentposition.first][currentposition.second].end()
        );

        // 다음 예상 위치 구하기
        pair<int,int> nextPos = getNextPosition(nexthorses[0].second, currentposition);
        int nextColor = -1;

        if(!inRange(nextPos) || nextColor == 2) { // 파란색이나 이동 불가 위치
            nexthorses[0].second = convertNotRangeDirection(nexthorses[0].second);
            nextPos = getNextPosition(nexthorses[0].second, currentposition);

            if(!inRange(nextPos) || nextColor == 2){
                nextPos = currentposition;
            }
            else {
                nextColor = map[nextPos.first][nextPos.second];
            }
        }

        if(nextColor == 0) { // 흰색
            moveHorse(nextPos, nexthorses);
        } 
        else if(nextColor == 1) { // 빨간색
            vector<pair<int,int>> reversenexthorses;
            for(int h = nexthorses.size()-1; h > -1; h--) {
                reversenexthorses.push_back(nexthorses[h]);
            }
            moveHorse(nextPos, reversenexthorses);
        }

        refreshHorsePositions();

        if(horses[nextPos.first][nextPos.second].size() >= 4) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getinputs();

    int turn = 1; 

    while(turn < 1001) {
        if(simulate()) {
            break;
        }
        turn++; 
    }

    cout << turn;
    
    return 0;
}