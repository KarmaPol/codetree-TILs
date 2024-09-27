import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static String a;

    static void shiftRight() {
        String[] chars = a.split("");
        String lastChar = chars[n-1];
        
        for(int i = n-1; i > 0; i--) {
            chars[i] = chars[i-1];
        }

        chars[0] = lastChar;
        a = String.join("", chars);
    }

    static String encodeRunLength() {
        StringBuilder sb = new StringBuilder();
        
        String[] chars = a.split("");
        String prev = chars[0];
        int count = 1;
        sb.append(prev);
        for(int i = 1; i < n; i++) {
            if(chars[i].equals(prev)) {
                count++;
            }
            else {
                sb.append(count);
                prev = chars[i];
                sb.append(prev);
                count = 1;
            }
        }
        sb.append(count);

        return sb.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        a = br.readLine();
        n = a.length();

        int maxLength = 100;
        for(int i = 0; i < n-1; i++) {
            shiftRight();
            String encodedString = encodeRunLength();

            maxLength = Math.min(maxLength, encodedString.length());
        }

        System.out.println(maxLength);
    }
}