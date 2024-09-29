import java.util.*;
import java.io.*;

public class Main {
    static int n, m;

    static int[] bombs = new int [105];
    static int[] tempBombs = new int[105];

    
    static boolean bomb() {
        int prev = bombs[0], combo = 1, last = n-1;
        boolean isBomb = false;
        if(prev == 0) return false;

        for(int i = 1; i < n; i++) {
            if(bombs[i] == 0) {
                last = i-1;
                break;
            }

            if(prev != bombs[i] && combo >= m) {
                for(int j = 0; j < combo; j++) {
                    bombs[i - 1 - j] = 0;
                }
                prev = bombs[i];
                combo = 1;
                isBomb = true;
            }
            else if(prev != bombs[i] && combo < m) {
                prev = bombs[i];
                combo = 1;
            }
            else {
                combo++;
            }
        }

        if(combo >= m) {
            for(int j = 0; j < combo; j++) {
                bombs[last - j] = 0;
            }
            isBomb = true;
        }

        return isBomb;
    }

    static void gravity() {
        for(int i = 0; i < n; i++) {
            tempBombs[i] = 0;
        }
        
        int t = 0;
        for(int i = 0; i < n; i++) {
            if(bombs[i] == 0) continue;

            tempBombs[t] = bombs[i];
            t++;
        }

        for(int i = 0; i < n; i++) {
            bombs[i] = tempBombs[i];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++) {
            bombs[i] = Integer.parseInt(br.readLine());
        }

        while(bomb()) {
            gravity();
        }
        // bomb();
        // gravity();

        StringBuilder sb = new StringBuilder();
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(bombs[i] == 0) break;
            count++;
        }
        sb.append(count).append("\n");
        for(int i = 0; i < n; i++) {
            if(bombs[i] == 0) break;
            sb.append(bombs[i]).append("\n");
        }

        System.out.print(sb.toString());
    }
}