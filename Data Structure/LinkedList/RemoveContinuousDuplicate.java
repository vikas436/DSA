package com.learn.linkedlist;

import java.util.Scanner;

import static com.learn.linkedlist.Linkedlist.getInputList;
import static com.learn.linkedlist.Linkedlist.print;

public class RemoveContinuousDuplicate {
    static Node headNode;

    private static void removeDuplicate(Node head) {
        if(head == null || head.next==null) return;
        Node backPtr = head;
        head = head.next;
        while(head != null) {
            if(head.data == backPtr.data) {
                head = head.next;
            } else {
                backPtr.next = head;
                backPtr = head;
                head = head.next;
            }
        }
        backPtr.next = null;
    }

    private static void recursiveRemoveDuplicate(Node head) {
        if(head == null) return;

        if(headNode.data == head.data) {
            recursiveRemoveDuplicate(head.next);
        } else {
            headNode.next = head;
            headNode = head;
            recursiveRemoveDuplicate(head.next);
        }
        headNode.next = null;
    }

    public static void main(String args[]) {
        System.out.println("Program to remove duplicates from a sorted linked list");
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the size of list");
        int n = scanner.nextInt();
        Node head = getInputList(n);
        print(head);
        headNode = head;
        recursiveRemoveDuplicate(head);
        System.out.println("O/p after remove duplicates");
        print(head);
    }
}
