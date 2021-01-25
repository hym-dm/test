**
* Definition for singly - linked list.
* struct ListNode {
    *int val;
    *struct ListNode* next;
    *
};
*/
bool hasCycle(struct ListNode* head) {
    struct ListNode* fast = head;
    struct  ListNode* slow = head;
    if (head == NULL || head->next == NULL)
        return false;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }

    return false;

}
**
*Definition for singly - linked list.
* struct ListNode {
    *int val;
    *struct ListNode* next;
    *
};
*/
struct ListNode* detectCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return NULL;
    int flag = 0;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            // {
                // flag = 1;
            break;
        // }
    }
    // struct ListNode* t = fast;
    if (fast == NULL || fast->next == NULL)
        return NULL;
    fast = head;
    // fast = t;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;

        //if(slow == fast)
       // break;
    }
    //if(slow != NULL)
    return slow;
}
**
*Definition for singly - linked list.
* struct ListNode {
    *int val;
    *struct ListNode* next;
    *
};
*/


struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    else
    {
        struct  ListNode* p = head->next;
        head->next = NULL;
        struct  ListNode* q = p;
        while (q != NULL)
        {
            q = q->next;
            p->next = head;
            head = p;
            p = q;
        }
    }
    return head;
}
**
*struct ListNode {
    *int val;
    *struct ListNode* next;
    *
};
*/

/**
 *
 * @param pListHead ListNode类
 * @param k int整型
 * @return ListNode类
 */
    struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    int len = 0;
    struct ListNode* p = pListHead;
    struct ListNode* q = pListHead;
    if (pListHead == NULL)
        return NULL;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    if (k > len)
        return NULL;
    for (int i = 1; i <= len - k; i++)
    {
        q = q->next;
    }
    return q;
}
struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL)
    {
        return head;
    }
    struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode));
    t->next = head;
    t->val = 0;
    struct ListNode* cur = head->next;
    struct ListNode* last = head;
    while (cur != NULL)
    {
        if (last->val <= cur->val)
            last = last->next;
        else
        {
            struct ListNode* pre = t;
            while (pre->next->val <= cur->val)
            {
                pre = pre->next;
            }
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
        }
        cur = last->next;
    }
    return t->next;
}
/*
struct ListNode {
   int val;
   struct ListNode *next;
   ListNode(int x) :
       val(x), next(NULL) {
   }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
            return pHead;
        ListNode* pre = NULL;
        ListNode* cur = pHead;
        ListNode* nextnode = pHead->next;
        while (nextnode != NULL)
            if (cur->val != nextnode->val)
            {
                pre = cur;
                cur = nextnode;
                nextnode = nextnode->next;
            }
            else
            {
                while (nextnode && cur->val == nextnode->val)
                    nextnode = nextnode->next;
                if (pre == NULL)
                    pHead = nextnode;
                else
                    pre->next = nextnode;
                while (cur != nextnode)
                {
                    ListNode* p = cur;
                    cur = cur->next;
                    free(p);
                }
                if (nextnode != NULL)
                    nextnode = nextnode->next;
            }
        return pHead;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL)
        return head;
    struct ListNode* p = head;
    struct ListNode* pre = NULL;
    while (p != NULL)
    {
        if (p->val == val)
        {
            if (pre == NULL)
                head = p->next;
            else
                pre->next = p->next;
            free(p);
        }
        else
            pre = p;
        if (pre == NULL)
            p = head;
        else
            p = pre->next;
    }
    return head;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* fast, * slow;
    fast = slow = head;
    while (fast && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
**
*Definition for singly - linked list.
* struct ListNode {
    *int val;
    *struct ListNode* next;
    *
};
*/


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL && l2 == NULL)
        return NULL;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    struct ListNode* head;
    if (l1->val < l2->val)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }
    struct ListNode* tail = head;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val <= l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1 != NULL)
        tail->next = l1;
    if (l2 != NULL)
        tail->next = l2;
    return head;
}
