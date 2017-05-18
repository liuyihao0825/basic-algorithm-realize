/*****************************************************************
Question:
Given a linked list, remove the nth node from the end of list and return its head.

Case:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
*****************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        assert(head);

        ListNode* retNode = head;

        ListNode* fast = head;
        ListNode* slow = head;
        int i = 0;

        if (n == 1 && head->next == NULL)
        {
            delete head;
            head = NULL;
            return NULL;
        }

        while (fast->next != NULL)
        {
            fast = fast->next;
            i++;

            if (i > n)
            {
                slow = slow->next;
            }
        }

        if (slow == head && i < n)
        {
            retNode = head->next;
            delete slow;
            slow = NULL;

            return retNode;
        }

        ListNode* tmp = slow->next;
        slow->next = tmp->next;

        delete tmp;
        tmp = NULL;

        return retNode;
    }
};