import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    public static class Node {
        int occurences;
        Map<Character, Node> children = new HashMap<Character, Node>();
        
        public Node() {
            occurences = 1;
        }
    }

    public static class Trie {
        Node root;
        
        public Trie() {
            root = new Node();
        }
        public void addName(String s) {
            Node current = root;
            for(int i = 0; i < s.length(); i++) {
                if(current.children.containsKey(s.charAt(i))) {
                    // Move to node and increment occurences
                    current = current.children.get(s.charAt(i));
                    current.occurences++;
                } else {
                    // Make new node and update current
                    Node newNode = new Node();
                    current.children.put(s.charAt(i), newNode);
                    current = newNode;
                }
            }
        }
        public int findPartial(String s) {
            Node current = root;
            for(int i = 0; i < s.length(); i++) {
                if(!current.children.containsKey(s.charAt(i))) {
                    return 0; // Key not found
                } else {
                    current = current.children.get(s.charAt(i));
                }
            }
            return current.occurences;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Trie trie = new Trie();
        for(int a0 = 0; a0 < n; a0++){
            String op = in.next();
            String contact = in.next();
            if(op.equals("add")) {
                trie.addName(contact);
            } else {
                System.out.println(trie.findPartial(contact));
            }
        }
    }
}

