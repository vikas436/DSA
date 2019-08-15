package com.learn.linkedlist;

import java.util.Random;
import java.util.Scanner;

public class Linkedlist {
    static Scanner scanner = new Scanner(System.in);
    Node head ;

    public static void print(Node head) {
        // count is used to avoid looping
        Long count = 0L;
        System.out.println("printing the linked list: ");
        while(head != null) {
            System.out.print(head.data+" ");
            head = head.next;

            if(count++>2000) break;
        }
        System.out.println();
    }

    public static Node getListBySize(int n) {
        Node head = null;
        for (int i=0;i<n;i++) {
            Random random = new Random();
            head = insertInLast(head, random.nextInt(10));
        }
        return head;
    }

    public static Node getInputList(int n) {
        Node head = null;
        for (int i=0;i<n;i++) {
            int num = scanner.nextInt();
            head = insertInLast(head, num);
        }
        return head;
    }

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
        Linkedlist list = new Linkedlist();
        list.head = new Node(1);
        list.head.next = new Node(2);
        list.head.next.next = new Node(3);
        list.head.next.next.next = new Node(4);

        print(list.head);
    }
}
