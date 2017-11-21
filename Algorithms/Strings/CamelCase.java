import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        in.close();
        System.out.println(numWords(s));
    }
    private static int numWords(String str)
    {
        int count = 1;
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch >= 'A' && ch <= 'Z') {
                count++;
            }
        }
        return count;
    }
}
