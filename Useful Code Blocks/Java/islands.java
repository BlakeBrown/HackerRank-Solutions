package com.blakelockbrown;

import java.util.Comparator;
import java.util.HashMap;
import java.util.PriorityQueue;

public class Main {

    public static void visitIsland(int[][] matrix, int x, int y) {
        matrix[x][y] = 0;
        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                if(i >= 0 && j >= 0 && i < 10 && j < 10 && matrix[i][j] == 1) {
                    visitIsland(matrix, i, j);
                }
            }
        }
    }

    public static void main(String[] args) {

//        int[] arr = {5, 2, 7, 10, 100, 666, 123, 18};
//
//        PriorityQueue<Integer> queue = new PriorityQueue<Integer>(Comparator.reverseOrder());
//        for (int i = 0; i < arr.length; i++) {
//            queue.add(arr[i]);
//        }
//        for (int i = 0; i < 3; i++) {
//            System.out.println(queue.poll());
//        }
        int[][] matrix = new int[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                matrix[i][j] = 0;
            }
        }
        // Create islands
        matrix[0][0] = 1;
        matrix[0][1] = 1;
        matrix[1][1] = 1;
        matrix[1][5] = 1;
        matrix[1][6] = 1;
        matrix[2][8] = 1;
        matrix[5][5] = 1;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
        int count = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (matrix[i][j] == 1) {
                    visitIsland(matrix, i, j);
                    count++;
                }
            }
        }
        System.out.println(count);

    }
}

