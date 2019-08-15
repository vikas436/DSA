package com.learn.linkedlist;

import java.util.Scanner;

import static com.learn.linkedlist.Linkedlist.getInputList;
import static com.learn.linkedlist.Linkedlist.print;

public class ReverseInGroupByK {

    private static Node reverseInGroupByK(Node head) {


        return null;
    }

    public static void main(String args[]) {
        System.out.println("Program for Reverse a linked list in group of k");
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the size of list");
        int n = scanner.nextInt();
        Node head = getInputList(n);
        print(head);
        head = reverseInGroupByK(head);
        System.out.println("O/p after Reverse a linked list in group of k");
        print(head);
    }

}
/*
#include <bits/stdc++.h>
using namespace std;

int repeatNBy3(vector<int>& vec) {
    int cnt1=0,cnt2=0,cnt3=0;
    int val1 = -100000, val2 = -100000,val3=-100000;
    for(int i=0;i<vec.size();i++) {
        if(vec[i]==val1) cnt1++;
        else if(vec[i]==val2) cnt2++;
        else if (vec[i] == val3) cnt3++;
        else{
            if(cnt1>0 && cnt2>0 && cnt3>0) {
                cnt1--;cnt2--;cnt3--;
            } else {
                if(cnt1==0) {
                    val1=vec[i];
                    cnt1=1;
                } else if(cnt2==0) {
                    val2 = vec[i];
                    cnt2=1;
                } else if(cnt3==0) {
                    val3=vec[i];
                    cnt3=1;
                }
            }
        }
    }
    cnt1=0;cnt2=0;cnt3=0;
    for(int i=0;i<vec.size();i++) {
        if(val1==vec[i]) cnt1++;
        if(val2==vec[i]) cnt2++;
        if (val3 == vec[i]) cnt3++;
    }
    int n3 = vec.size()/3;
    if(cnt1>n3) return val1;
    if (cnt2 > n3) return val2;
    if (cnt3 > n3) return val3;
    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    cout << repeatNBy3(vec);
    return 0;
}


find n/3 repeat elements

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

vector< vector<char> > topDownLeftRight(vector< vector<char> >&vec, vector< vector<char> >&arr ,int n, int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i==0 && j==0) continue;
            if(i==0) {
                if(vec[i][j]=='S' && vec[i][j-1]!='X') arr[i][j] = arr[i][j-1]+1;
            }
            else if(j==0) {
                if(vec[i][j]=='S' && vec[i-1][j]!='X') arr[i][j] = arr[i-1][j]+1;
            } else {
                if(vec[i][j] == 'S' && vec[i][j-1]!='X' && vec[i-1][j]!='X') {
                    arr[i][j] = min(arr[i-1][j],arr[i][j-1])+1;
                } else if(vec[i][j] == 'S' && vec[i][j-1]!='X') {
                    arr[i][j] = arr[i][j-1]+1;
                } else if(vec[i][j] == 'S' && vec[i-1][j]!='X') {
                    arr[i][j] = arr[i-1][j]+1;
                }
            }
        }
    }
}

vector< vector<char> > bottomUpRightLeft(vector< vector<char> >&vec, vector< vector<char> >&arr ,int n, int m) {
    for(int i=n-1;i>=0;i--) {
        for(int j=m-1;j>=0;j--) {
            if(i==n-1 && j==m-1) continue;
            if(i==n-1) {
                if(vec[i][j]=='S' && vec[i][j+1]!='X') arr[i][j] = arr[i][j+1]+1;
            }
            else if(m-1==j) {
                if(vec[i][j]=='S' && vec[i+1][j]!='X') arr[i][j] = arr[i+1][j]+1;
            } else {
                if(vec[i][j] == 'S' && vec[i][j+1]!='X' && vec[i+1][j]!='X') {
                    arr[i][j] = min(arr[i+1][j],arr[i][j+1])+1;
                } else if(vec[i][j] == 'S' && vec[i][j+1]!='X') {
                    arr[i][j] = arr[i][j+1]+1;
                } else if(vec[i][j] == 'S' && vec[i+1][j]!='X') {
                    arr[i][j] = arr[i+1][j]+1;
                }
            }
        }
    }
}

vector< vector<char> > solve(vector< vector<char> >&vec,int n, int m) {
    vector< vector<char> >arr(n, vector<char>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(vec[i][j]=='S') arr[i][j] = MAX;
            if(vec[i][j]=='D') arr[i][j] = 0;
            if(vec[i][j]=='X') arr[i][j] = -1;
        }
    }
    topDownLeftRight(vec, arr, n, m);
    bottomUpRightLeft(vec, arr, n, m);
    return arr;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector< vector<char> >vec(n, vector<char>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>vec[i][j];

    vector< vector<char> >arr = solve(vec, n, m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}






*/