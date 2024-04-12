#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int map[25][25];
vector<pair<int, int> > routes[25];
bool isNonClock[25]; // false가 기본
vector<pair<int, int> > tempRoute;
int mateNum[25];
int heads[25];

int teamNum = 0;
int answer = 0;
int n, m, k;

int visited[25][25];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool inRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < n;
}

void dfs(int team, int currY, int currX) {
    int count = 0;
    for(int i = 0; i < 4; i++) {
        int nextY = currY + dy[i];
        int nextX = currX + dx[i];

        if(!inRange(nextY, nextX)) continue;
        if(visited[nextY][nextX]) continue;
        if(map[nextY][nextX] == 0) continue;
        count++;
    }
    if(count == 0) {
        routes[team] = tempRoute;
        return;
    }

    for(int i = 0; i < 4; i++) {
        int nextY = currY + dy[i];
        int nextX = currX + dx[i];
        
        if(!inRange(nextY, nextX)) continue;
        if(visited[nextY][nextX]) continue;
        if(map[nextY][nextX] == 0) continue;
        if(map[currY][currX] == 1 && map[nextY][nextX] != 4 && map[nextY][nextX] != 3) continue;

        visited[nextY][nextX] = 1;
        tempRoute.push_back({nextY, nextX});
        dfs(team, nextY, nextX);
        visited[nextY][nextX] = 0;
        tempRoute.pop_back();
    }
}

void getRoutes() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] != 1) continue;

            int currY = i, currX = j;
            
            visited[currY][currX] = 1;
            tempRoute.push_back({currY, currX});
            dfs(teamNum, currY, currX);
            tempRoute.pop_back();
            teamNum++;
        }
    }
}

void printRoutes() {
    cout << teamNum << '\n';
    for(int i = 0 ; i < teamNum; i++) {
        for(int j = 0; j < routes[i].size(); j++) {
            cout << routes[i][j].first << ":" << routes[i][j].second << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void getMateNum() {
    for(int i = 0 ;i < n; i++) {
        int count = 0;
        for(int j = 0; j < routes[i].size(); j++) {
            if(map[routes[i][j].first][routes[i][j].second] != 4){
                count++;
            }
        }
        mateNum[i] = count;
    }
}

void walk(int t) {
    int currentHead = heads[t];
    if(!isNonClock[t]) { // 시계 방향 
        heads[t] = (currentHead+1)%routes[t].size();
    } else { // 반시계 방향
        heads[t] = (currentHead-1+routes[t].size())%routes[t].size();
    }
}

bool isHit(int ballY, int ballX) {
    for(int i = 0; i < teamNum; i++) {
        int currentHead = heads[i];
        for(int j = 0; j < mateNum[i]; j++) {
            int currentMate;
            if(!isNonClock[i]) { // 시계 방향 
                currentMate = (currentHead-j+routes[i].size())%routes[i].size();
            } else { // 반시계 방향
                currentMate = (currentHead+j)%routes[i].size();                
            }

            int currentMateY, currentMateX;
            tie(currentMateY, currentMateX) = routes[i][currentMate];
            if(ballY == currentMateY && ballX == currentMateX) { // 맞았다
                answer += (j+1)*(j+1);
                
                if(!isNonClock[i]) { // 시계 방향 
                    currentHead = (currentHead-mateNum[i]+1+routes[i].size())%routes[i].size();
                } else { // 반시계 방향
                    currentHead = (currentHead+mateNum[i]-1)%routes[i].size();
                }
                // 방향 반대로, 머리 교체
                isNonClock[i] = !isNonClock[i];
                heads[i] = currentHead;

                return true;
            }
        }
    }

    return false;
}

void throwBall(int round) {
    pair<int,int> nextRound[4] = {{1,0}, {0,1}, {-1,0}, {0, -1}};
    pair<int,int> nextLine[4] = {{0,1}, {-1, 0}, {0, -1}, {1, 0}};
    pair<int, int> startPoints[4] = {{0, 0}, {n-1, 0}, {n-1, n-1}, {0, n-1}};

    int r = round/n;
    int c = round%n;

    int currentY = startPoints[r].first + nextRound[r].first*c;
    int currentX = startPoints[r].second + nextRound[r].second*c;
    
    for(int i = 0; i < n; i++) {
        int nextY = currentY + nextLine[r].first*i;
        int nextX = currentX + nextLine[r].second*i;
        
        if(isHit(nextY, nextX)) break;
    }
}

int main() {
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    getRoutes();
    getMateNum();
    int round = 0;
    while(round < k) {
        // 각 팀 머리 사람 한 칸 이동
        for(int i = 0; i < teamNum; i++) {
            walk(i);
        }
        // 각 라운드마다 공 던지기
        throwBall(round);
        round++;
    }
    cout << answer;

    return 0;
}