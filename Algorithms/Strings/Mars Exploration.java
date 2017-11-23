import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.next();
        in.close();
        
        int count =0;
        String original = "SOS";
        for(int i = 0; i < str.length();i++)
        {
            if(str.charAt(i)!=original.charAt(i%3))
                count++;
        }
        System.out.println(count);
    }
}
