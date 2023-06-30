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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode* target = head -> next;
        if(target -> next != NULL ){
            ListNode* rb_next_target = target -> next;
            head-> next = swapPairs(rb_next_target);
        } else {
            head -> next = target -> next;
        }
        target -> next = head;
        return target;
    }
};

int main() {
    ListNode node_one = ListNode(1);
    ListNode node_two = ListNode(2);
    ListNode node_three = ListNode(3);
    ListNode node_four = ListNode(4);
    node_one.next = &node_two;
    node_two.next = &node_three;
    node_three.next = &node_four;
    Solution sol = Solution();
    ListNode *node = sol.swapPairs(&node_one);

    while(node) {
       cout << node -> val << " ";
       node = node -> next;
    }
}
