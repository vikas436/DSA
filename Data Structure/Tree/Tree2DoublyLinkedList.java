package com.learn.tree;

import static com.learn.tree.TreeConstruction.initilization;

public class Tree2DoublyLinkedList {
    TreeNode pre = null;

    public static void main(String args[]) {
        System.out.println("Program for Tree2DoublyLinkedList");
        TreeNode node = initilization();
        Tree2DoublyLinkedList tree2DoublyLinkedList = new Tree2DoublyLinkedList();
        tree2DoublyLinkedList.convertToList(node);
        printLeftSideDoublyList(node);
        printRightSideDoublyList(node);
    }

    private void convertToList(TreeNode node) {
        if(node == null) return;

        convertToList(node.left);
        node.left = pre;
        if(pre != null) {
            pre.right= node;
        }
        pre = node;
        convertToList(node.right);
    }

    private static void printLeftSideDoublyList(TreeNode node) {
        System.out.println("doubly list from left");
        if(node == null) return;;
        while(node.left != null) {
            node = node.left;
        }
        while(node != null) {
            System.out.print(node.data + " ");
            node = node.right;
        }
        System.out.println();
    }

    private static void printRightSideDoublyList(TreeNode node) {
        System.out.println("doubly list from right");
        if(node == null) return;
        while(node.right != null) {
            node = node.right;
        }
        while(node != null) {
            System.out.print(node.data + " ");
            node = node.left;
        }
    }
}

/**
* Program for Tree2DoublyLinkedList
 * 15
 * 10 12 15 25 30 35 -1 -1 -1 -1 -1 5 -1 -1 -1
 * doubly list from left
 * 25 12 30 10 5 35 15
* */