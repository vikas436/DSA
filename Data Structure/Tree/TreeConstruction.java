package com.learn.tree;

import java.util.Scanner;

import static com.learn.tree.PreOrderTreeConstruction.getLevelOrderManner;

public class TreeConstruction {

    static Scanner scanner = new Scanner(System.in);

    static TreeNode constructBSTree(TreeNode headNode, int data) {
        if(headNode == null) {
            headNode = new TreeNode(data);
            return headNode;
        }
        TreeNode head = headNode;
        while(head != null) {
            if(head.left == null && head.data>=data) {
                head.left = new TreeNode(data);
                break;
            }
            if(head.right == null && head.data<data) {
                head.right = new TreeNode(data);
                break;
            }
            if(head.data<data) {
                head = head.right;
            } else {
                head = head.left;
            }
        }
        return headNode;
    }

    static void inOrderTraversal(TreeNode node) {
        if(node==null) return;
        inOrderTraversal(node.left);
        System.out.print(node.data+ " ");
        inOrderTraversal(node.right);

    }

    static TreeNode initilization() {
        int size = scanner.nextInt();
        int arr []= new int[size];
        for(int i=0;i<size;i++) {
            arr[i] = scanner.nextInt();
        }
        TreeNode node = getLevelOrderManner(arr, size);
        return node;
    }
    public static void main(String args[]) {
        System.out.println("Program for construct binary search tree ");
        int num = scanner.nextInt();
        TreeNode treeNode = null;
        for(int i=0;i<num; i++) {
            treeNode = constructBSTree(treeNode, scanner.nextInt());
        }
        System.out.println("Printing tree inorder ");
        inOrderTraversal(treeNode);
    }
}
