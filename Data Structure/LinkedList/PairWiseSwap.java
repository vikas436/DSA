package com.learn.linkedlist;

import java.util.Scanner;

import static com.learn.linkedlist.Linkedlist.getInputList;
import static com.learn.linkedlist.Linkedlist.print;

public class PairWiseSwap {

    private static Node pairWiseSwap(Node head) {
        if(head == null || head.next ==null) return head;
        Node backHead = head, headNode = head.next;
        head = head.next;
        while (head != null ) {
            Node temp = head.next;
            head.next = backHead;

            if(temp != null && temp.next != null) {
               backHead.next = temp.next;
               backHead = temp;
            } else {
                backHead.next = temp;
            }

            if(temp != null && temp.next != null)
                head = temp.next;
            else head = null;
        }
        return headNode;
    }

    public static void main(String args[]) {
        System.out.println("Program to pair wise Swap nodes in a linked list");
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the size of list");
        int n = scanner.nextInt();
        Node head = getInputList(n);
        print(head);
        head = pairWiseSwap(head);
        System.out.println("O/p after pair wise swapping nodes");
        print(head);
    }

}
