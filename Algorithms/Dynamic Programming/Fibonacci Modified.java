import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int A, B, N;
        A = s.nextInt();
        B = s.nextInt();
        N = s.nextInt();
        BigInteger[] array = new BigInteger[N];
        array[0] = BigInteger.valueOf(A);
        array[1] = BigInteger.valueOf(B);
        for(int i = 2; i < N; i++) {
            array[i] = (array[i-1].multiply(array[i-1])).add(array[i-2]);
        }
        System.out.println(array[N-1]);
    }
}