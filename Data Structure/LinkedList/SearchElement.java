package com.learn.linkedlist;

import java.util.Scanner;

import static com.learn.linkedlist.Linkedlist.getListBySize;
import static com.learn.linkedlist.Linkedlist.print;

public class SearchElement {

    private static boolean search(Node head, int data) {
        if(head == null) return false;
        return (head.data == data) ? true : search(head.next, data);
    }

    public static void main(String args[]) {
        System.out.println("Program for search element in linked list");
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the size of list");
        int n = scanner.nextInt();
        Node head = getListBySize(n);
        print(head);
        System.out.println("Enter to number to search in list");
        int data = scanner.nextInt();
        System.out.println("Is given element found in list: " + search(head, data));
    }

}
