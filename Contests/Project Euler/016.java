import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T > 0) {
        	if(T < 0) {
        		break;
        	}
        	int N, answer = 0;
        	N = sc.nextInt();
        	BigInteger x = BigInteger.valueOf(1);
        	for(int i = 0; i < N; i++) {
        		x = x.multiply(BigInteger.valueOf(2));
        	}
        	String s = x.toString();
        	for(int i = 0; i < s.length(); i++) {
        		answer+= Integer.parseInt(s.substring(i, i+1));
        	}
        	System.out.println(answer);
        }
    }
}