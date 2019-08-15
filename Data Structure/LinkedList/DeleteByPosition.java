package com.learn.linkedlist;

import java.util.Scanner;

import static com.learn.linkedlist.InsertInLast.insertInLast;
import static com.learn.linkedlist.Linkedlist.print;

public class DeleteByPosition {

    private static Node deleteByPos(Node head, int pos) {
        if(head == null) {
            return head;
        }
        int n=1;
        Node backPtr = head, headNode = head;
        if(pos == 1 ) {
            return head.next;
        }
        head = head.next;
        n++;
        while (head != null && pos!=n) {
            backPtr = head;
            head = head.next;
        }
        if(head != null)
            backPtr.next = head.next;
        return headNode;
    }

    public static void main(String args[]) {
        System.out.println("Program for Linked List to delete by pos");
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node head = null;
        for(int i=0; i<n; i++) {
            head = insertInLast(head, i+1);
        }
        print(head);
        int pos = scanner.nextInt();
        head = deleteByPos(head, pos);
        print(head);
    }

}
