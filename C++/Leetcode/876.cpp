//
// Created by 김지민 on 2023/06/30.
//

const // It is a const object...
class nullptr_t
{
public:
    template<class T>
    inline operator T*() const // convertible to any type of null non-member pointer...
    { return 0; }

    template<class C, class T>
    inline operator T C::*() const   // or any type of null member pointer...
    { return 0; }

private:
    void operator&() const;  // Can't take address of nullptr

} nullptr = {};

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int num = 0;
        ListNode* node = head;
        while (1) {
            if(node -> next == NULL) {
                break;
            }
            node = node -> next;
            num += 1;
        }
        for (int i = 0; i < (num+1)/2; i++) {
            head = head -> next;
        }
        return head;
    }
};