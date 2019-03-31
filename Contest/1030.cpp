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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        ListNode* p = head;
        while(p){
            ListNode* q = p->next;
            if(q){
                while(q){
                    if(q->val > p->val){
                        res.push_back(q->val);
                        break;
                    }
                    q = q->next;
                }
                if(!q)
                    res.push_back(0);
            }
            else
                res.push_back(0);
            p = p->next;
        }
        return res;
    }
};