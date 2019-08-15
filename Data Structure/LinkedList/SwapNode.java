package com.learn.linkedlist;

import java.util.Scanner;

import static com.learn.linkedlist.Linkedlist.getInputList;
import static com.learn.linkedlist.Linkedlist.print;

public class SwapNode {

    private static Node swapNode(Node head, int x, int y) {
        Node xPre=head, yPre=head, xNode=null, yNode=null, headNode = head;
        while(head != null) {
            if(x == head.data) xNode = head;
            if(y == head.data) yNode = head;
            if(xNode == null) xPre = head;
            if(yNode == null) yPre = head;
            head = head.next;
        }
        if(xNode==xPre || yNode == yPre) {
            if(xNode == xPre) {
                headNode = yNode;
                Node temp = xNode.next;
                yPre.next = xNode;
                xNode.next = yNode.next;
                if(yNode != temp)
                    yNode.next = temp;
                else yNode.next = xNode;
            }
            else {
                headNode = xNode;
                Node temp = yNode.next;
                xPre.next = yNode;
                yNode.next = xNode.next;
                if(xNode != temp)
                    xNode.next=temp;
                else xNode.next = yNode;
            }
        } else {
            Node temp = yNode.next;
            xPre.next = yNode;
            if(yNode != xNode.next)
                yNode.next = xNode.next;
            else yNode.next = xNode;
            yPre.next = xNode;
            if(xNode != temp)
                xNode.next = temp;
            else xNode.next = yNode;
        }
        return headNode;
    }

    public static void main(String args[]) {
        System.out.println("Program to Swap nodes in a linked list");
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the size of list");
        int n = scanner.nextInt();
        Node head = getInputList(n);
        print(head);
        int x = scanner.nextInt(), y = scanner.nextInt();
        head = swapNode(head, x, y);
        System.out.println("O/p after swap nodes");
        print(head);
    }
}
