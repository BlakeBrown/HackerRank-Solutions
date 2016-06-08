import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	int N;
    	N = sc.nextInt();
    	BigInteger sum = BigInteger.valueOf(0);
    	for(int i = 0; i < N; i++) {
 			BigInteger x = sc.nextBigInteger();
    		sum = sum.add(x);
    	}
    	String answer = sum.toString();
    	System.out.print(answer.substring(0,10));
    }
}