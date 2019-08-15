package com.learn.linkedlist;

import java.util.Scanner;

import static com.learn.linkedlist.Linkedlist.getInputList;
import static com.learn.linkedlist.Linkedlist.print;

public class MergeTwoSortedList {

    private static Node merge2SortedList(Node head1, Node head2) {
        if(head1 == null) return head2;
        if(head2 == null) return head1;
        Node head , temp;
        if(head1.data<head2.data) {
            head = head1;
            temp=head1;
            head1 = head1.next;
        } else {
            head = head2;
            temp=head2;
            head2 = head2.next;
        }

        while (head1 != null && head2!= null) {
            if(head1.data< head2.data) {
                temp.next = head1;
                temp = temp.next;
                head1 = head1.next;
            } else {
                temp.next = head2;
                temp = temp.next;
                head2 = head2.next;
            }
        }
        while (head1 != null) {
            temp.next = head1;
            temp = temp.next;
            head1 = head1.next;
        }
        while (head2 != null) {
            temp.next = head2;
            temp = temp.next;
            head2 = head2.next;
        }
        return head;
    }

    public static void main(String args[]) {
        System.out.println("Program for merge 2 sorted linked list");
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the size of list");
        int n = scanner.nextInt();
        Node head1 = getInputList(n);
        n = scanner.nextInt();
        Node head2 = getInputList(n);
        print(head1);
        print(head2);
        Node head = merge2SortedListReverse(head1, head2);
        System.out.println("O/p after merge 2 sorted linked list");
        print(head);
    }

    private static Node merge2SortedListReverse(Node head1, Node head2) {
        Node  temp=null, back = null;
        while (head1 != null && head2!= null) {
            if(head1.data< head2.data) {
                back = temp;
                temp= head1;
                Node tmp = head1.next;
                temp.next = back;
                temp = head1;
                head1 = tmp;
            } else {
                back = temp;
                temp= head2;
                Node tmp = head2.next;
                temp.next = back;
                temp = head2;
                head2 = tmp;
            }
        }
        while (head1 != null) {
            back = temp;
            temp= head1;
            Node tmp = head1.next;
            temp.next = back;
            temp = head1;
            head1 = tmp;
        }
        while (head2 != null) {
            back = temp;
            temp= head2;
            Node tmp = head2.next;
            temp.next = back;
            temp = head2;
            head2 = tmp;
        }
        return temp;
    }
}
