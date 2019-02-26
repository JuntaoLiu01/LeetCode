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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = 0,lb=0;
        ListNode *p=headA,*q=headB; 
        while(p){
            la++;
            p = p->next;
        }
        while(q){
            lb++;
            q = q->next;
        }
        if(!la || !lb)
            return NULL;
        int dis = abs(la-lb);
        p = headA;q=headB;
        if(la >= lb){          
            while(dis--)
                p = p->next;
            while(p && q){
                if(p==q)
                    return p;
                p = p->next;
                q = q->next;
            }
        }
        else{
            while(dis--)
                q = q->next;
            while(p && q){
                if(p==q)
                    return p;
                p = p->next;
                q = q->next;
            }
        }
        return NULL;
    }
};