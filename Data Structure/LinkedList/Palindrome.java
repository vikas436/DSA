package com.learn.linkedlist;

import java.util.Scanner;

import static com.learn.linkedlist.Linkedlist.getInputList;
import static com.learn.linkedlist.Linkedlist.print;

public class Palindrome {

    static Node left;

    private static boolean palindrome(Node right) {
        if(right == null) return true;
        boolean val = palindrome(right.next);
        if(left.data == right.data) {
            left = left.next;
        } else return false;
        return val;
    }

    public static void main(String args[]) {
        System.out.println("Program for check if a singly linked list is palindrome");
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the size of list");
        int n = scanner.nextInt();
        Node head = getInputList(n);
        print(head);
        left = head;
        System.out.println("is given list is palindrome : " + palindrome(head));
    }
}
