#include <iostream>
#include <vector>

using namespace std;

vector<int> horizontals(4);
vector<int> verticals(4);
int map[25][25];
int n = 0;
int m = 0;
int x = 0;
int y = 0;

bool isValidMove(int a, int b) {
    if(a >= n || a < 0 || b >= m || b < 0) return false;
    return true;
}

int goRight() {
    if(!isValidMove(y, x+1)) {
        return -1;
    }
    x++;

    int first = horizontals[0];
    horizontals.erase(horizontals.begin());
    horizontals.push_back(first);

    int current = map[y][x];
    if(current == 0) {
        map[y][x] = horizontals[1];
        horizontals[1] = 0;
    }
    else {
        horizontals[1] = current;
        map[y][x] = 0;
    }

    verticals[1] = horizontals[1];
    verticals[3] = horizontals[3];

    return horizontals[3];
}

int goLeft() {
    if(!isValidMove(y, x-1)) {
        return -1;
    }
    x--;

    int last = horizontals[horizontals.size()-1];
    horizontals.pop_back();
    horizontals.insert(horizontals.begin(), last);

    int current = map[y][x];
    if(current == 0) {
        map[y][x] = horizontals[1];
    }
    else {
        horizontals[1] = current;
        map[y][x] = 0;
    }

    verticals[1] = horizontals[1];
    verticals[3] = horizontals[3];

    return horizontals[3];
}

int goUp() {
    if(!isValidMove(y-1, x)) {
        return -1;
    }
    y--;

    int last = verticals[verticals.size()-1];
    verticals.pop_back();
    verticals.insert(verticals.begin(), last);

    int current = map[y][x];
    if(current == 0) {
        map[y][x] = verticals[1];
        verticals[1] = 0;
    }
    else {
        verticals[1] = current;
        map[y][x] = 0;
    }

    horizontals[1] = verticals[1];
    horizontals[3] = verticals[3];

    return verticals[3];
}

int goDown() {
    if(!isValidMove(y+1, x)) {
        return -1;
    }
    y++;

    int first = verticals[0];
    verticals.erase(verticals.begin());
    verticals.push_back(first);

    int current = map[y][x];
    if(current == 0) {
        map[y][x] = verticals[1];
        verticals[1] = 0;
    }
    else {
        verticals[1] = current;
        map[y][x] = 0;
    }

    horizontals[1] = verticals[1];
    horizontals[3] = verticals[3];

    return verticals[3];
}


int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    vector<int> answer;

    int t = 0;
    cin >> n >> m >> x >> y >> t;

    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < m; j++) {
            cin >> map[i][j];
        }
    }

    while(t--) {
        int dir;
        cin >> dir;

        int curr_answer;
        if(dir == 1) {
            curr_answer = goRight();
        }
        else if(dir == 2) {
            curr_answer = goLeft();
        }
        else if(dir == 3) {
            curr_answer = goUp();
        }
        else if(dir == 4) {
            curr_answer = goDown();
        }

        if(curr_answer != -1) {
            answer.push_back(curr_answer);
        }
    }

    for(int a : answer) {
        cout << a << '\n';
    }

    return 0;
}