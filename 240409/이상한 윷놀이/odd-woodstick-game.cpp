#include <iostream>
#include <vector>

using namespace std;

int map[15][15]; // 색 표기
vector<pair<int, int>> horses[15][15]; // <말 번호, 방향>

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
    }
}

pair<int, int> getNextPosition(int dir, pair<int, int> current) {
    pair<int, int> next = {current.first + diry[dir], current.second + dirx[dir]};
    return next;
}

bool inRange(pair<int, int> next) {
    return next.first >= 0 && next.first < n && next.second >= 0 && next.second < n;
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

pair<int,int> findPiece(int h) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(auto horse : horses[i][j]) {
                if(horse.first == h) {
                    return {i, j};
                }
            }
        }
    }
}

void printHorses() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << i << ' ' << j << '\n';
            for(auto horse : horses[i][j]) {

                cout << horse.first << '\n';
            }
        }
    }
    cout << '\n';
}

bool isEnd() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(horses[i][j].size() >= 4) return true;
        }
    }
    return false;
}

void deleteHorses(pair<int,int> currentposition, int idx) {
    // 추린 말들은 제거
    horses[currentposition.first][currentposition.second].erase(
        horses[currentposition.first][currentposition.second].begin() + idx,
        horses[currentposition.first][currentposition.second].end()
    );
}

bool simualte() {
    for(int i = 0; i < k; i++) {
        pair<int,int> currentposition = findPiece(i);
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

        // 다음 예상 위치 구하기
        pair<int,int> nextPos = getNextPosition(nexthorses[0].second, currentposition);
        int nextColor = map[nextPos.first][nextPos.second];

        if(!inRange(nextPos)) { // 바깥일 경우 보정
            nexthorses[0].second = (nexthorses[0].second % 2 == 0) ? (nexthorses[0].second + 1) : (nexthorses[0].second - 1);
            nextPos = getNextPosition(nexthorses[0].second, currentposition);
        }

        if(nextColor == 0) { // 흰색
            moveHorse(nextPos, nexthorses);
            deleteHorses(currentposition, idx);
        } 
        else if(nextColor == 1) { // 빨간색
            vector<pair<int,int>> reversenexthorses;
            for(int h = nexthorses.size()-1; h > -1; h--) {
                reversenexthorses.push_back(nexthorses[h]);
            }
            moveHorse(nextPos, reversenexthorses);
            deleteHorses(currentposition, idx);
        }
        else if(nextColor == 2) { // 파란색
            nexthorses[0].second = (nexthorses[0].second % 2 == 0) ? (nexthorses[0].second + 1) : (nexthorses[0].second - 1);
            nextPos = getNextPosition(nexthorses[0].second, currentposition);

            if(inRange(nextPos) && map[nextPos.first][nextPos.second] != 2) {
                moveHorse(nextPos, nexthorses);
                deleteHorses(currentposition, idx);
            }
        }
        // printHorses();

        if(isEnd()) {
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
        if(simualte()) break;
        turn++; 
    }

    if(turn == 1001) turn = -1;
    cout << turn;
    
    return 0;
}