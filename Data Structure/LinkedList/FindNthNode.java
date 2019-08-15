package com.learn.linkedlist;

import java.util.Scanner;

import static com.learn.linkedlist.Linkedlist.getListBySize;
import static com.learn.linkedlist.Linkedlist.print;

public class FindNthNode {
    static int cnt =1;

    private static Integer searchNthNum(Node head, int data) {
        if(head == null) return null;
        return (cnt++ == data) ? (head == null) ? null : head.data : searchNthNum(head.next, data);
    }

    public static void main(String args[]) {
        System.out.println("Program for search nth element in linked list");
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the size of list");
        int n = scanner.nextInt();
        Node head = getListBySize(n);
        print(head);
        System.out.println("Enter Nth number to search in list");
        int data = scanner.nextInt();
        System.out.println("Given nth number : " + searchNthNum(head, data));
    }

}
