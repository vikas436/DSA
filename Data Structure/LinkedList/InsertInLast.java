package com.learn.linkedlist;

import java.util.Scanner;

public class InsertInLast {

    public static Node insertInLast(Node head ,int data) {

        if(head == null) {
            head = new Node(data);
            return head;
        }

        Node headNode = head;
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = new Node(data);
        return headNode;
    }

    public static void main(String args[]) {
        System.out.println("Program for Linked List insert in last !!!");
        Scanner scanner = new Scanner(System.in);

        Node head = null;
        int n = scanner.nextInt();
        for(int i=0; i<n; i++) {
            head = insertInLast(head, i+1);
        }

        Linkedlist linkedlist = new Linkedlist();
        linkedlist.print(head);
    }
}
