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
    		int N = sc.nextInt(), answer = 0;
    		BigInteger x = BigInteger.valueOf(1);
    		for(int i = 2; i <= N; i++) {
    			x = x.multiply(BigInteger.valueOf(i));
    		}
    		String s = x.toString();
    		for(int i = 0; i < s.length(); i++) {
    			answer += Integer.parseInt(s.substring(i, i+1));
    		}
    		System.out.println(answer);
    		T--;
    	}
    }
}