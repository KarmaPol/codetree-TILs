import java.util.*;
import java.io.*;

public class Main {
    static int[][] arr = new int[25][25];
    static int[][] count = new int[25][25];

    static int dy[] = {-1, 1, 0, 0};
    static int dx[] = {0, 0, -1, 1};

    static int n, m, t;

    static int moveBalls() {
        int[][] nextCount = new int[25][25];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(count[i][j] == 1) {
                    int max = 0, nextDir = -1;
                    for(int d = 0; d < 4; d++) {
                        int nextY = dy[d] + i, nextX = dx[d] + j;

                        if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) continue;
                        if(max < arr[nextY][nextX]) {
                            max = arr[nextY][nextX];
                            nextDir = d;
                        }
                    }

                    if(nextDir == -1) continue;
                    nextCount[i + dy[nextDir]][j + dx[nextDir]]++;
                }
            }
        }

        int answer = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(nextCount[i][j] >= 2)
                    nextCount[i][j] = 0;
                
                if(nextCount[i][j] == 1) 
                    answer++;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                count[i][j] = nextCount[i][j];
            }
        }

        return answer;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            count[Integer.parseInt(st.nextToken())-1][Integer.parseInt(st.nextToken())-1] = 1;
        }

        int answer = 0;
        for(int i = 0; i < t; i++) {
            answer = moveBalls();   
        }

        System.out.println(answer);
    }
}