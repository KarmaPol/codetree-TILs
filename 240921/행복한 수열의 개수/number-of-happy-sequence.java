import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static int m;

    static int arr[][] = new int [105][105];
    static int[] seq = new int[105];

    static boolean isHappy() {
        int combo = 1, maxCnt = 1;

        for(int i = 1; i < n; i++) {
            if(seq[i-1] == seq[i])
                combo++;
            else
                combo = 1;
            maxCnt = Math.max(maxCnt, combo);
        }

        return maxCnt >= m;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int HappyCount = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                seq[j] = arr[i][j];
            }
            if(isHappy()) {    
                HappyCount++;
            }
        }

        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n; i++) {
                seq[i] = arr[i][j];
            }
            if(isHappy()) {
                HappyCount++;
            }
        }

        System.out.println(HappyCount);
    }
}