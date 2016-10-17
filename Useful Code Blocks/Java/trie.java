package com.company;

import java.io.*;
import java.util.*;
import java.util.PriorityQueue;

public class Main {

    class Node {
        int occurences = 0;
        char letter;
        Map<Character, Node> children = new HashMap<>();
    }

    class Trie {
        Node root = new Node();

        public void insert(String s) {
            Node current = root;
            // Insert whole String into trie
            for(int i = 0; i < s.length(); i++) {
                if(current.children.get(s.charAt(i)) == null) {
                    // Create new node
                    Node new_node = new Node();
                    new_node.letter = s.charAt(i);
                    current.children.put(s.charAt(i), new_node);
                }
                Node next = current.children.get(s.charAt(i));
                next.occurences++;
                // Update current
                current = next;
            }
        }
        public List<String> minimum(List<String> result, Node current) {
            if(result.size() == 0) {
                for(Character key : current.children.keySet()) {
                    result.add(key.toString());
                    // Create the initial keys
                    System.out.println(key + " occurs " + current.children.get(key).occurences);
                }
            }
            return result;
        }
    }


    public static void main(String[] args) {
        Trie trie = new Trie();
        String[] arr = {"arre", "aram", "array", "test1", "test2"};
        for(int i = 0; i < arr.length; i++) {
            trie.insert(arr[i]);
        }
        //System.out.println(trie.root.children.get("a"
        List<String> result = new ArrayList<>();
        trie.minimum(result, trie.root);
    }
}

