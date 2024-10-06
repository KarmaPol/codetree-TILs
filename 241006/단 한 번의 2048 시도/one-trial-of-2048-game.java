import java.util.*;
import java.io.*;

public class Main {
    static int[][] map = new int[4][4];
    static int[][] nextMap = new int[4][4];

    static int n = 4;

    static void initNextMap() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                nextMap[i][j]= 0;
            }
        }
    }

    static void rotate() {
        initNextMap();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                nextMap[i][j] = map[3 - j][i];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                map[i][j] = nextMap[i][j];
            }
        }
    }

    static void drop() {
        initNextMap();

        for(int j = 0; j < n; j++) {
            int keep = -1, temp = n-1;
            for(int i = n - 1; i > -1; i--) {
                if(map[i][j] == 0) continue;

                if(keep == -1) {
                    keep = map[i][j];
                }
                else if(keep == map[i][j]) {
                    nextMap[temp--][j] = keep*2;
                    keep = -1;
                }
                else {
                    nextMap[temp--][j] = keep;
                    keep = map[i][j];
                }
            }

            if(keep != -1) {
                nextMap[temp--][j] = keep;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                map[i][j] = nextMap[i][j];
            }
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        char dir = br.readLine().charAt(0);

        int[] dirMapper = new int[128];
        dirMapper['D'] = 0;
        dirMapper['R'] = 1;
        dirMapper['U'] = 2;
        dirMapper['L'] = 3;

        int rotateNumber = dirMapper[dir];

        for(int i = 0; i < rotateNumber; i++) {
            rotate();
        }
        
        drop();

        for(int i = 0; i < 4 - rotateNumber; i++) {
            rotate();
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                sb.append(map[i][j]).append(" ");
            }
            sb.append("\n");
        }

        System.out.println(sb.toString());
    }
}