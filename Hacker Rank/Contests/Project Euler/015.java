import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        BigInteger[][] matrix = new BigInteger[501][501];
        for(int i = 0; i <= 500; i++) {
            for(int j = 0; j <= 500; j++) {
                if(i == 0 || j == 0) {
                    matrix[i][j] = BigInteger.valueOf(1);
                } else {
                    matrix[i][j] = matrix[i-1][j].add(matrix[i][j-1]);
                }
            }
        }
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T > 0) {
            int N, M; 
            N = sc.nextInt();
            M = sc.nextInt();
            System.out.println(matrix[N][M].mod(BigInteger.valueOf(1000000007)));
            T--;
        }
    }
}