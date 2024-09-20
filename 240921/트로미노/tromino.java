import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static int m;

    static int arr[][] = new int[205][205];

    static int getBlockSum1(int y, int x) {
        int maxSum = 0;
        
        int sum = 0;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                sum += arr[y + i][x + j];
            }
        }

        int dy[] = {0, 0, 1, 1};
        int dx[] = {0, 1, 0, 1};

        for(int i = 0; i < 4; i++) {
            maxSum = Math.max(maxSum, sum - arr[y + dy[i]][x + dx[i]]);
        }
        return maxSum;
    }

    static int getBlockSum2Vert(int y, int x) {
        int maxSum = 0;

        int horiSum = 0;
        for(int i = 0; i < 3; i++) {
            horiSum += arr[y + i][x];
        }

        maxSum = Math.max(maxSum, horiSum);

        return maxSum;
    }


    static int getBlockSum2Hori(int y, int x) {
        int maxSum = 0;

        int vertSum = 0;
        for(int i = 0; i < 3; i++) {
            vertSum += arr[y][x + i];
        }

        maxSum = Math.max(maxSum, vertSum);

        return maxSum;
    }

    static boolean isBlockSum1(int y, int x) {
        return y + 1 < n && x + 1 < m;
    }

    static boolean isBlockSum2Hori(int y, int x) {
        return x + 2 < m;
    }

    static boolean isBlockSum2Vert(int y, int x) {
        return y + 2 < n;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int maxSum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isBlockSum1(i, j)) {
                    maxSum = Math.max(maxSum, getBlockSum1(i, j));
                }
                if(isBlockSum2Hori(i, j)) {
                    maxSum = Math.max(maxSum, getBlockSum2Hori(i, j));
                }
                if(isBlockSum2Vert(i, j)) {
                    maxSum = Math.max(maxSum, getBlockSum2Vert(i, j));
                }
            }
        }

        System.out.println(maxSum);
    }
}