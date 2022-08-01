package com.company;

import java.util.Scanner;

public class Main {

    public static class Node {
        Node left;
        Node right;
        int data;
    }

    public static class BinaryTree {
        public Node root;

        public void insert(int x) {
            Node newNode = new Node();
            newNode.data = x;
            if(root == null) {
                // Insert as root
                root = newNode;
                return;
            }
            Node current = root;
            while(true) {
                while(x > current.data) {
                    if(current.right != null) {
                        // Go right
                        current = current.right;
                    } else {
                        // Insert right
                        current.right = newNode;
                        return;
                    }

                }
                while(x < current.data) {
                    if(current.left != null) {
                        // Go left
                        current = current.left;
                    } else {
                        // Insert left
                        current.left = newNode;
                        return;
                    }
                }
            }
        }
        public void inOrderTraversal(Node node) {
            if (node != null) {
                inOrderTraversal(node.left);
                System.out.println(node.data);
                inOrderTraversal(node.right);
            }

        }
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.insert(2);
        tree.insert(5);
        tree.insert(6);
        tree.insert(1);
        tree.insert(3);
        tree.insert(10);
        tree.inOrderTraversal(tree.root);
//        System.out.println(tree.root.right.right.data);
//        String[] arr = {"xyz", "rawrrr"};
//        Scanner scanner = new Scanner(System.in);
//        int number = scanner.nextInt();
//        System.out.println(number);
    }
}

