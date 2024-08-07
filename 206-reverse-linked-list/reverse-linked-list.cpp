/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //Itterative approach
        // if(head==NULL || head->next==NULL) return head;
        // ListNode* curr=head;
        // ListNode* prev=NULL;
        // ListNode* nxt=NULL;
        // while(curr){
        //     nxt=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=nxt;
        // }
        // return prev;

        //Recursive approach
        // if(head==NULL || head->next==NULL) return head;
        // ListNode* rest=reverseList(head->next);
        // head->next->next=head;
        // head->next=NULL;
        // return rest;
        
        if(head==NULL || head->next==NULL) return head;
        ListNode* rest=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return rest;
    }
};