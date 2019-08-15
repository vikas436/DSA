package com.learn.linkedlist;

import java.util.Scanner;

import static com.learn.linkedlist.Linkedlist.getListBySize;
import static com.learn.linkedlist.Linkedlist.print;

public class FrequencyOfKey {

    private static int frequencyOfkey(Node head, int data) {
        if(null == head) return 0;
        return (head.data == data) ? 1+frequencyOfkey(head.next, data) : frequencyOfkey(head.next, data);
    }

    public static void main(String args[]) {
        System.out.println("Program for counts the number of times a given int occurs");
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the size of list");
        int n = scanner.nextInt();
        Node head = getListBySize(n);
        print(head);
        System.out.println("Enter to number to count in list");
        int data = scanner.nextInt();
        System.out.println("#Of times given number occurs : " + frequencyOfkey(head, data));
    }
}
