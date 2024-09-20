import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static int coins[][] = new int[25][25];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++) {
                coins[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int frameSize = 2;
        int max = Integer.MIN_VALUE;
        for(int i = 0; i + frameSize < n; i++) {
            for(int j = 0; j + frameSize < n; j++) {
                int total = 0;
                for(int k = 0; k <= frameSize; k++) {
                    for(int p = 0; p <= frameSize; p++) {
                        total += coins[i + k][j + p];
                    }
                }
                max = Math.max(max, total);
            }
        }

        System.out.println(max);
    }
}