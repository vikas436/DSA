package com.learn.linkedlist;

import java.util.Scanner;

import static com.learn.linkedlist.InsertInLast.insertInLast;

public class DeleteByKey {

    public static Node deleteByKey(Node head, int key) {
        if(head == null) {
            System.out.println("Linked List is empty");
            return null;
        }
        if(head.data == key) {
            return head.next;
        }
        Node backPtr = head, headNode=head;
        if(head.next == null) return head;
        head = head.next;

        while (head != null && head.data != key) {
            backPtr = head;
            head = head.next;
        }
        if(head != null)
            backPtr.next = head.next;
        return headNode;
    }
    public static void main(String args[]) {
        System.out.println("Program for Linked List delete by key !!!");
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        Node head = null;
        for (int i=0;i<n;i++) {
            head = insertInLast(head, i+1);
        }
        Linkedlist linkedlist = new Linkedlist();
        linkedlist.print(head);

        int key = scanner.nextInt();
        head = deleteByKey(head, key);
        linkedlist.print(head);
    }
}
