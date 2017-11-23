import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        queries:
        for(int i =0;i<n;i++)
        {
            String str = scan.next();
            char[] find = "hackerrank".toCharArray();
            int findIndex = 0;
            for(char ch:str.toCharArray())
            {
                if(find[findIndex]==ch)
                {
                    findIndex++;
                }
                if(findIndex==find.length)
                {
                    System.out.println("YES");
                    continue queries;
                }
            }
            System.out.println("NO");
        }
    }
}
