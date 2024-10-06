import java.util.*;
import java.io.*;

public class Main {
    static int n, m, k;

    static int[][] map = new int[105][105];

    static boolean isPossible(int y, int x) {
        for(int i = 0; i < m; i++) {
            if(y+1 > n-1) return false;
            if(map[y + 1][x + i] == 1) return false;
        }
        return true;
    }

    static void setBlock(int y, int x) {
        for(int i = 0; i < m; i++) {
            map[y][x + i] = 1;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken()); k--;

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int y = -1, x = k;
        while(isPossible(y, x)) {
            y++;
        }

        setBlock(y, x);

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                sb.append(map[i][j]).append(" ");
            }
            sb.append("\n");
        }
        System.out.println(sb.toString());
    }
}