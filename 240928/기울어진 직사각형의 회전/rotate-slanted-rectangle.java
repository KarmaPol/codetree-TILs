import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static int r, c, m1, m2, m3, m4, dir;

    static int[][] map = new int[105][105];
    
    static void printMap() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                System.out.print(map[i][j]);
                System.out.print(' ');
            }
            System.out.print('\n');
        }
    }

    static void rotateReverseClock() {
        int[] dx;
        int[] dy;
        int[] moveNums;

        if(dir == 0) {
            dx = new int[] {-1, -1, 1, 1};
            dy = new int[] {1, -1, -1, 1};
            moveNums = new int[]{m1, m2, m1, m2};
        }
        else {
            dx = new int[] {-1, -1, 1, 1};
            dy = new int[] {-1, 1, 1, -1};
            moveNums = new int[]{m2, m1, m2, m1};
        }

        int[][] tempMap = new int[105][105];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                tempMap[i][j] = map[i][j];
            }
        }
        
        int x = r-1, y = c-1;
        for(int d = 0; d < 4; d++) {
            for(int q = 0; q < moveNums[d]; q++) {
                int nx = x + dx[d], ny = y + dy[d];
                tempMap[nx][ny] = map[x][y];
                x = nx; y = ny;
            }
        }


        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                map[i][j] = tempMap[i][j];
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        m1 = Integer.parseInt(st.nextToken());
        m2 = Integer.parseInt(st.nextToken());
        m3 = Integer.parseInt(st.nextToken());
        m4 = Integer.parseInt(st.nextToken());
        dir = Integer.parseInt(st.nextToken());

        rotateReverseClock();
        printMap();
    }
}