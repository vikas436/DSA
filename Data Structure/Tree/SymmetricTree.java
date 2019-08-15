package com.learn.tree;

import java.util.Scanner;

import static com.learn.tree.PreOrderTreeConstruction.getLevelOrderManner;

public class SymmetricTree {

    public static void main(String args[]) {
        System.out.println("Program for SymmetricTree");
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int arr []= new int[size];
        for(int i=0;i<size;i++) {
            arr[i] = scanner.nextInt();
        }
        TreeNode node = getLevelOrderManner(arr, size);
        System.out.println(symmetric(node, node));
    }

    private static boolean symmetric(TreeNode node1, TreeNode node2) {
        if(node1==null && node2==null) return true;
        if(node1==null || node2==null) return false;

        if(node1.data != node2.data) return false;
        System.out.println("data "+node1.data+" "+node2.data);
        return symmetric(node1.left, node2.right) && symmetric(node1.right, node2.left);
    }
}
