package com.learn.tree;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

import static com.learn.tree.TreeConstruction.inOrderTraversal;

public class PreOrderTreeConstruction {

    static Scanner scanner = new Scanner(System.in);
    static int ind=0;

    static TreeNode preOrderTreeConstruct(TreeNode head, int arr[], int size) {
        if(head !=null && head.data == -1) return null;

        if(ind>=size) return null;

        head = new TreeNode(arr[ind++]);

        head.left = preOrderTreeConstruct(head, arr, size);
        head.right = preOrderTreeConstruct(head, arr, size);
        return head;
    }

    static void inOrderArrangement(TreeNode head) {
        if(head == null) return;
        if(head.left != null && head.left.data==-1) {
            head.left=null;
        }
        if(head.right != null && head.right.data==-1) {
            head.right = null;
        }
        inOrderArrangement(head.left);
        inOrderArrangement(head.right);
    }

    static TreeNode getTreePreOrderManner(int arr[], int size) {
        TreeNode head = null;
        head = preOrderTreeConstruct(head, arr, size);
        inOrderArrangement(head);
        return head;
    }

    static TreeNode getLevelOrderManner(int arr[], int size) {
        ind=0;
        Queue<TreeNode> que = new LinkedList<>();

        if(ind>=size || arr[ind]==-1) return null;

        TreeNode head = new TreeNode(arr[ind++]);
        que.add(head);
        while (!que.isEmpty() && ind<size) {
            TreeNode temp = que.peek();
            que.remove();

            if(arr[ind]!=-1) {
                temp.left = new TreeNode(arr[ind++]);
                que.add(temp.left);
            } else ind++;
            if(arr[ind]!=-1) {
                temp.right = new TreeNode(arr[ind++]);
                que.add(temp.right);
            } else ind++;

        }


        return head;
    }

    public static void main(String args[]) {
        System.out.println("Program for construct pre order ");
        int size = scanner.nextInt();
        int arr [] = new int[size];
        for(int i=0;i<size;i++) {
            arr[i] = scanner.nextInt();
        }
        TreeNode head = getLevelOrderManner(arr, size);
        System.out.println("InOrder traversal of binary tree");
        inOrderTraversal(head);
    }
}
