package com.learn.linkedlist;

import java.util.Scanner;

import static com.learn.linkedlist.Linkedlist.getInputList;
import static com.learn.linkedlist.Linkedlist.print;

public class ReverseList {


    public static Node reverseList(Node head) {
        if(head == null) return null;
        Node back = null, next;
        while (head!=null) {
            next = head.next;
            head.next = back;
            back = head;
            head = next;
        }
        return back;
    }

    static Node headNode = null;
    private static void recursiveReverseListWithGlobalPtr(Node head) {
        if (head == null || head.next == null) {
            headNode = head;
            return;
        }
        Node back = head;
        recursiveReverseList(head.next);
        head.next.next = back;
        back.next = null;
    }

    private static Node recursiveReverseList(Node head) {
        Node retNode;
        if (head == null || head.next == null) {
            return head;
        }
        retNode = recursiveReverseList(head.next);
        head.next.next = head;
        head.next = null;
        return retNode;
    }

    public static void main(String args[]) {
        System.out.println("Program for Reverse a linked list");
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the size of list");
        int n = scanner.nextInt();
        Node head = getInputList(n);
        print(head);
        headNode = recursiveReverseList(head);
//        recursiveReverseListWithGlobalPtr(head);
        System.out.println("O/p after Reverse a linked list");
        print(headNode);
    }
}
