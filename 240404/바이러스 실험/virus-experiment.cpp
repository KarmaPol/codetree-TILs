#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int praymap[15][15];
int addedpray[15][15];
priority_queue<int, vector<int>, less<int>> virusmap[15][15]; // pq는 기본이 내림차순

pair<int,int> sexmap[8] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

int main() {

    int n, m, k;

    cin >> n >> m >> k;

    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n; j++) {
            praymap[i][j] = 5;
        }
    }

    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> addedpray[i][j];
        }
    }

    int y, x, l;
    while(m--) {
        cin >> y >> x >> l;
        virusmap[y-1][x-1].push(l);
    }

    while(k--) {
        vector<pair<int,pair<int,int>>> deadvirus; // <수명, <위치정보>>
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                vector<pair<int,pair<int,int>>> tempvirus;
                for(int v = 0; v < virusmap[i][j].size(); v++) {
                    int currentvirus = virusmap[i][j].top();
                    virusmap[i][j].pop();

                    // 양분 섭취 가능 여부 체크
                    if(praymap[i][j] < currentvirus) { // 사망
                        deadvirus.push_back({currentvirus,{i,j}});
                        continue;
                    }

                    // 양분 섭취
                    praymap[i][j] -= currentvirus;
                    tempvirus.push_back({currentvirus+1, {i,j}});

                    // 번식
                    if((currentvirus+1) % 5 == 0) {
                        for(int dir = 0; dir < 8; dir++) {
                            int nexty = sexmap[dir].first + i;
                            int nextx = sexmap[dir].second + j;

                            if(nexty < 0 || nexty >= n || nextx < 0 || nexty >= n) continue;

                            tempvirus.push_back({1, {nexty,nextx}});
                        }
                    }
                }
                
                for(auto tv : tempvirus) {
                    virusmap[tv.second.first][tv.second.second].push(tv.first);
                }
            }
        }

        // 죽은 바이러스 양분화
        for(auto db : deadvirus) {
            int currenty = db.second.first;
            int currentx = db.second.second;
            int currentl = db.first;

            currentl /= 2;
            praymap[currenty][currentx] += currentl;
        }

        // 양분 추가
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                praymap[i][j] += addedpray[i][j];
            }
        }   
    }

    int answer = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            answer += virusmap[i][j].size();
        }
    }

    cout << answer;

    return 0;
}