**
* Definition for singly - linked list.
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
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
int getlenoflist(struct ListNode* head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;
    int lena = getlenoflist(headA);
    int lenb = getlenoflist(headB);
    struct ListNode* longlist, * shortlist;
    if (lena > lenb)
    {
        longlist = headA;
        shortlist = headB;
    }

    else
    {
        longlist = headB;
        shortlist = headA;
    }
    int offset = abs(lena - lenb);
    while (offset-- > 0)
        longlist = longlist->next;
    while (longlist != NULL)
    {
        if (shortlist == longlist)
            return longlist;
        shortlist = shortlist->next;
        longlist = longlist->next;
    }
    return NULL;
}

/*
struct ListNode {
   int val;
   struct ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        int arr[900] = { 0 };
        int i = 0;
        int len = 0;
        ListNode* p = A;
        if (A == NULL)
            return false;
        while (p != NULL)
        {
            arr[i++] = p->val;
            len++;
            p = p->next;
        }
        int start = 0;
        int last = len - 1;
        while (start < last)
        {
            if (arr[start++] != arr[last--])
                return false;
        }
        return true; // write code here
    }
};

/*
struct ListNode {
   int val;
   struct ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        if (pHead == NULL)
            return NULL;
        ListNode* less, * lesstail, * great, * greattail;
        less = lesstail = (ListNode*)malloc(sizeof(ListNode*));
        great = greattail = (ListNode*)malloc(sizeof(ListNode*));
        while (pHead != NULL)
        {
            if (pHead->val < x)
            {
                lesstail->next = pHead;
                lesstail = lesstail->next;
            }
            else
            {
                greattail->next = pHead;
                greattail = greattail->next;
            }
            pHead = pHead->next;
        }
        lesstail->next = great->next;
        greattail->next = NULL;
        pHead = less->next;
        free(great);
        free(less);
        return pHead;
    }

};