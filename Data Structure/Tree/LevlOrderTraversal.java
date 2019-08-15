package com.learn.tree;

import java.util.Scanner;

import static java.lang.Math.max;

public class LevlOrderTraversal {

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("program for LevlOrderTraversal");
        System.out.println("Enter number of nodes including null nodes");
        int num = scanner.nextInt();
        int arr[] = new int[num];
        System.out.println("Enter level order");
        for(int i=0;i<num;i++) {
            arr[i] = scanner.nextInt();
        }
        TreeNode node = PreOrderTreeConstruction.getLevelOrderManner(arr, num);
        System.out.println("No of nodes in tree : "+getNoOfNodes(node));
        printLevelOrderRecursively(node);
        reversePrintLevelOrderRecursively(node);
    }

    private static void printLevelOrderRecursively(TreeNode node) {
        int height = getHeight(node);
        System.out.println("Height of tree is: " + height);
        for(int i=0;i<height;i++) {
            printLevelOrder(node, i);
            System.out.println();
        }
    }

    private static void reversePrintLevelOrderRecursively(TreeNode node) {
        int height = getHeight(node);
        System.out.println("Height of tree is: " + height);
        for(int i=height-1;i>=0;i--) {
            printLevelOrder(node, i);
            System.out.println();
        }
    }

    private static void printLevelOrder(TreeNode node, int level) {
        if(node==null) return;
        if(level == 0) {
            System.out.print(node.data+" ");
            return;
        }
        printLevelOrder(node.left, level-1);
        printLevelOrder(node.right, level-1);
    }

    private static int getHeight(TreeNode node) {
        if(node==null) return 0;
        return 1+max(getHeight(node.left), getHeight(node.right));
    }

    public static int getNoOfNodes(TreeNode node) {
        if(node == null) return 0;
        return 1+(getNoOfNodes(node.left) + getNoOfNodes(node.right));
    }
}
