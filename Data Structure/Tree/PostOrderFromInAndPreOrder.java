package com.learn.tree;
import java.util.Scanner;

import static com.learn.tree.PreOrderTreeConstruction.getLevelOrderManner;

public class PostOrderFromInAndPreOrder {

    static int ind = 0;

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("program for postOrderFromInAndPreOrder");
        System.out.println("Enter number of nodes in tree");
        int num = scanner.nextInt();
        int pre[] = new int[num];
        int in[] = new int[num];
        System.out.println("Enter pre-order");
        for(int i=0;i<num;i++) {
            pre[i] = scanner.nextInt();
        }
        System.out.println("Enter in-order");
        for(int i=0;i<num;i++) {
            in[i] = scanner.nextInt();
        }
        System.out.println("Output of postOrderFromInAndPreOrder");
        printPostOrderFromInAndPreOrder(pre, in, 0, num-1);
    }

    private static void printPostOrderFromInAndPreOrder(int[] pre, int[] in, int start, int end) {
        if(start>end) return;

        int index = getIndex(in, pre[ind++]);
        printPostOrderFromInAndPreOrder(pre, in, start, index-1);
        printPostOrderFromInAndPreOrder(pre, in, index +1 , end);
        System.out.print(in[index]+" ");
    }

    private static int getIndex(int[] in, int data) {
        for(int i=0;i<in.length;i++) {
            if(in[i] == data) return i;
        }
        return -1;
    }
}