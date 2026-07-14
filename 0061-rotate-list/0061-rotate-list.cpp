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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
        {
            return head;
        }
        int count = 0;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            count += 1;
            temp = temp->next;
        }
        int needed = k % count;

        int rot = 0;

        while (rot < needed)
        {
            temp = head;
            while (temp->next->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next->next = head;
            head = temp->next;
            temp->next = nullptr;
            rot += 1;
        }
        return head;
    }
};