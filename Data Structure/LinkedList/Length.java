package com.learn.linkedlist;

import java.util.Scanner;

import static com.learn.linkedlist.Linkedlist.getListBySize;
import static com.learn.linkedlist.Linkedlist.print;

public class Length {

    public static int length(Node head) {
        return  (head == null) ? 0 : 1 + length(head.next);
    }

    public static void main(String args[]) {
        System.out.println("Program for find the length of linked list");
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node head = getListBySize(n);
        print(head);
        System.out.println("Length of list: " + length(head));
    }
}
