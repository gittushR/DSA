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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* slow1 = head;
        ListNode* slow2 = nullptr; // Added nullptr initialization
        ListNode* fast1 = nullptr; // Added nullptr initialization
        ListNode* fast2 = head;
        
        int count1 = left - 1;
        int count2 = right;
        
        while (count1 > 0) {
            slow2 = slow1;
            slow1 = slow1->next;
            count1--;
        }
        
        while (count2 > 0) {
            fast1 = fast2;
            fast2 = fast2->next;
            count2--;
        }
        if(slow2!=nullptr){
        slow2->next = nullptr;
        }
        fast1->next = nullptr;
        
        ListNode* temp = slow1;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        int iteration = right - left + 1;
        
        while (iteration > 0) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            iteration--;
        }
        
        if (slow2 != nullptr) {
            slow2->next = prev;
        } else {
            head = prev; // Update head when left position is 1
        }
        
        slow1->next = fast2;
        
        return head;
    }
};