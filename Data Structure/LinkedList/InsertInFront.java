package com.learn.linkedlist;

import java.util.Scanner;

public class InsertInFront {

    public static Node insertInFront(Node head, int data) {
        if(head == null) {
            head = new Node(data);
            return head;
        }

        Node headNode = new Node(data);
        headNode.next = head;
        return headNode;
    }

    public static void main(String args[]) {
        System.out.println("Program for Linked List insert in front !!!");
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        Node head = null;
        for (int i=0;i<n;i++) {
            head = insertInFront(head, i+1);
        }
        Linkedlist linkedlist = new Linkedlist();
        linkedlist.print(head);
    }
}
