package com.learn.tree;
import java.util.Scanner;
import java.util.Stack;

import static com.learn.tree.PreOrderTreeConstruction.getLevelOrderManner;

public class Preorder {

    public static void main(String args[]) {
        System.out.println("Program for Inorder");
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int arr[] = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextInt();
        }
        TreeNode node = getLevelOrderManner(arr, size);
        preorderRecursive(node);
        System.out.println();
        preorderInterative(node);
    }

    private static void preorderRecursive(TreeNode node) {
        if (node == null) return;
        System.out.print(node.data + " ");
        preorderRecursive(node.left);
        preorderRecursive(node.right);
    }

    private static void preorderInterative(TreeNode node) {
        if (node == null) return;
        Stack<TreeNode> stack = new Stack<>();
        while (true) {
            if (node != null) {
                System.out.print(node.data +" ");
                if(node.right!=null)
                    stack.add(node.right);
                node = node.left;
            } else {
                if (stack.isEmpty()) break;
                node = stack.pop();
            }
        }
    }
}
/*
11
1 2 3 -1 -1 4 -1 -1 5 -1 -1
*/
