import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static int m;

    static int arr[][] = new int [105][105];

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
            int prev = arr[i][0];
            int combo = 0;
            for(int j = 0; j < n; j++) {
                if(prev == arr[i][j]) {
                    combo++;
                }
                else {
                    prev = arr[i][j];
                    combo = 0;
                }
                if(combo >= m) {
                    HappyCount++;
                    break;
                }
            }
            if(combo >= m) {    
                HappyCount++;
            }
        }

        for(int j = 0; j < n; j++) {
            int prev = arr[0][j];
            int combo = 0;
            for(int i = 0; i < n; i++) {
                if(prev == arr[i][j]) {
                    combo++;
                }
                else {
                    prev = arr[i][j];
                    combo = 0;
                }
                if(combo >= m) {
                    HappyCount++;
                    break;
                }
            }
            if(combo >= m) {
                HappyCount++;
            }
        }

        System.out.println(HappyCount);
    }
}