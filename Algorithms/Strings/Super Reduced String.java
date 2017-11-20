import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    private static String super_reduced_string(String s){
        Stack<Character> stack = new Stack<>();
        for(char ch: s.toCharArray())
        {
            if(!stack.isEmpty() && stack.peek()==ch)
                stack.pop();
            else
                stack.push(ch);
        }
        if(stack.isEmpty())
            return "Empty String";
        else
        {
            StringBuilder sb = new StringBuilder();
            while(!stack.isEmpty())
            {
                sb.append(stack.peek());
                stack.pop();
            }
            sb.reverse();
            String result = String.valueOf(sb);
            return result;
        }
        
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        String result = super_reduced_string(s);
        System.out.println(result);
    }
}
