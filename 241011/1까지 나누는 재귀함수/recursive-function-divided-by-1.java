import java.util.*;
import java.io.*;

public class Main {
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        while(n >= 1) {
            System.out.print(n + " ");
            if(n%2 == 0) n /= 2;
            else n /= 3;
        }
    }
}