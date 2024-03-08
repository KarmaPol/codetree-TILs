#include <iostream>
#include <vector>

using namespace std;

int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
int map[105][105];
vector<pair<int, int>> dragon;

int validateDir(pair<int, int> prev, pair<int, int> next) {
    int dy = next.first - prev.first;
    int dx = next.second - prev.second;

    if(dy == 0) {
        if(dx == 1) {
            return 0;
        } else {
            return 2;
        }
    } else {
        if(dy == 1) {
            return 3;
        } else {
            return 1;
        }
    }
}

void rotate() {
    vector<pair<int, int>> temp;

    temp.insert(temp.begin(), dragon[0]);

    for(int i = 1; i < dragon.size(); i++) {
        pair<int, int> prev = dragon[i-1];
        pair<int, int> next = dragon[i];
        pair<int, int> pivot = temp[0];

        int nextdir = (validateDir(prev, next)+3)%4;

        int mapy, mapx;
        int convertedy = pivot.first + dir[nextdir][0];
        int convertedx = pivot.second + dir[nextdir][1];

        temp.insert(temp.begin(), {convertedy, convertedx});  
        map[convertedy][convertedx] = 1;
    }

    for(int i = 1; i < dragon.size(); i++) {
        temp.push_back(dragon[i]);
    }

    dragon = temp;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, x, y, d, g, answer = 0;

    cin >> n;

    while(n--) {
        cin >> y >> x >> d >> g;
        int nexty = y + dir[d][0];
        int nextx = x + dir[d][1];
        dragon.clear();
        dragon.push_back({nexty, nextx});
        dragon.push_back({y, x});
        map[y][x] = 1;
        map[nexty][nextx] = 1;

        while(g--) {
            rotate();
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            // cout << map[i][j];
            if(map[i][j] == 1 && map[i+1][j+1] == 1 && map[i][j+1] == 1 && map[i+1][j] == 1) {
                answer++;
            } 
        }
        // cout << '\n';
    }

    cout << answer;

    return 0;
}