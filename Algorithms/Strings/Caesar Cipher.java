import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int length = scan.nextInt();
        String str = scan.next();
        int k = scan.nextInt();
        scan.close();
        
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < str.length();i++)
        {
            char ch = str.charAt(i);
            sb.append(encrypt(ch,k));
        }
        System.out.print(sb);
    }
   
    private static char encrypt(char x, int k)
    {
        if(!Character.isLetter(x))
            return x;
        char base = Character.isLowerCase(x)?'a':'A';
        return (char) ((x-base+k)%26+base);
    }
}
