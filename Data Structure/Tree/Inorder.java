package com.learn.tree;

import java.util.Scanner;
import java.util.Stack;

import static com.learn.tree.PreOrderTreeConstruction.getLevelOrderManner;

public class Inorder {

    public static void main(String args[]) {
        System.out.println("Program for Inorder");
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int arr[] = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextInt();
        }
        TreeNode node = getLevelOrderManner(arr, size);
        inorderRecursive(node);
        System.out.println();
        inorderInterative(node);
    }

    private static void inorderRecursive(TreeNode node) {
        if (node == null) return;
        inorderRecursive(node.left);
        System.out.print(node.data + " ");
        inorderRecursive(node.right);
    }

    private static void inorderInterative(TreeNode node) {
        if (node == null) return;
        Stack<TreeNode> stack = new Stack<>();
        while (true) {
            if (node != null) {
                stack.add(node);
                node = node.left;
            } else {
                if (stack.isEmpty()) break;
                node = stack.pop();
                System.out.print(node.data +" ");
                node = node.right;
            }
        }
    }
}
/*
11
1 2 3 -1 -1 4 -1 -1 5 -1 -1
*/