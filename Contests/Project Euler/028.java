import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

// Find a closed form solution using finite differences 
// Method shown here: http://www.mathblog.dk/project-euler-28-sum-diagonals-spiral/
// Although in this solution I have derived the formula slightly differently so that n is the actual spiral size
// I did this using the "differences trick": http://www.trans4mind.com/personal_development/mathematics/series/sumNaturalSquares.htm
public class Solution {

    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);
    	int T = sc.nextInt();

    	while(T > 0) {
    		BigInteger N = sc.nextBigInteger();
    		BigInteger Nsquared = N.multiply(N);
    		BigInteger Ncubed = N.multiply(N).multiply(N);
            // answer = (4(n^3)+ 3(n^2) + 8n - 9)/6
            BigInteger answer = Ncubed.multiply(BigInteger.valueOf(4)).add(Nsquared.multiply(BigInteger.valueOf(3))).add(N.multiply(BigInteger.valueOf(8))).subtract(BigInteger.valueOf(9)).divide(BigInteger.valueOf(6)).mod(BigInteger.valueOf(1000000007));
    		System.out.println(answer);
            T--;
    	}
    }
}