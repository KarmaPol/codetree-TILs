import java.util.*;
import java.io.*;

public class Main {
    static int n, r, c;

    static int[][] map = new int [105][105];

    static int[] dy = {-1, 1, 0, 0};
    static int[] dx = {0, 0, -1, 1};

    static int getHighestDir(int y, int x) {
        int nextDir = -1, maxValue = map[y][x];
        for(int i = 0; i < 4; i++) {
            int nextY = y + dy[i], nextX = x + dx[i];

            if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) continue;
            
            if(map[y][x] < map[nextY][nextX]) {
                nextDir = i; maxValue = map[nextY][nextX];
                break;
            }
        }

        return nextDir;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken()); r--;
        c = Integer.parseInt(st.nextToken()); c--;

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(map[r][c]).append(" ");
        while(true) {
            int nextDir = getHighestDir(r,c);
            if(nextDir == -1) break;

            r += dy[nextDir];
            c += dx[nextDir];
            sb.append(map[r][c]).append(" ");
        }

        System.out.println(sb.toString());
    }
}