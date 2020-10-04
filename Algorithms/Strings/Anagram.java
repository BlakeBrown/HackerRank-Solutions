import java.util.Scanner;

public class Solution {

    static boolean isAnagram(String a, String b) {
        if(a.length()!=b.length())
        return false;
        else
        {
           a=a.toLowerCase();
           b=b.toLowerCase();
           int f=0;
           for(int i=0;i<a.length();i++)
            {
                char c=a.charAt(i);
                int c1=0,c2=0;
                for(int j=0;j<a.length();j++)
                {
                    if(c==a.charAt(j))
                    c1++;
                    if(c==b.charAt(j))
                    c2++;

                }
                if(c1==c2)
                continue;
                else {
                    f=1;
                    break;
                }
            }
            if(f==1)
            return false;
            else
            return true;



        }


        
    }

    public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}
