import java.util.*;
import java.io.*;

public class Main {
    static int n;

    static int[][] map = new int [205][205];
    static int[][] tempMap = new int [205][205];

    static void initTempMap() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                tempMap[i][j] = 0;
            }
        }
    }

    static void copyMap() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                map[i][j] = tempMap[i][j];
            }
        }
    }
 
    static void bomb(int y, int x) {
        int[] dy = {-1, 0, 1, 0};
        int[] dx = {0, 1, 0, -1};

        int range = map[y][x];

        map[y][x] = 0;
        for(int i = 0; i < 4; i++) {
            for(int j = 1; j < range; j++) {
                int ny = y + j*dy[i];
                int nx = x + j*dx[i];

                if(ny < 0 || ny > n-1 || nx < 0 || nx > n-1) break;

                map[ny][nx] = 0;
            }
        }
    }

    static void gravity() {
        initTempMap();

        for(int j = 0; j < n; j++) {
            int t = n-1;
            for(int i = n-1; i > -1; i--) {
                if(map[i][j] != 0) {
                    tempMap[t][j] = map[i][j];
                    t--;
                }
            }
        }

        copyMap();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        int y = Integer.parseInt(st.nextToken()); y--;
        int x = Integer.parseInt(st.nextToken()); x--;

        bomb(y, x);
        gravity();

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                sb.append(map[i][j]).append(" ");
            }
            sb.append("\n");
        }

        System.out.print(sb.toString());
    }
}