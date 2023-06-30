//
// Created by 김지민 on 2023/06/30.
//

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }

        ListNode* rightside = reverseList(head -> next);
        ListNode* new_head = rightside;
        while(rightside -> next) {
            rightside = rightside -> next;
        }
        rightside -> next = head;
        head -> next = NULL;
        return new_head;
    }
};