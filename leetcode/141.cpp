/*
걍 쉬운 문제.
아이디어가 꽤나 중요하긴 함
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        while (head != nullptr)
        {
            if (head->val < -100000)
                return true;
            head->val = -100001;
            head = head->next;
        }

        return false;
    }
};