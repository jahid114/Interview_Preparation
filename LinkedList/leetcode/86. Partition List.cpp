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
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1, *h2, *cur1, *cur2, *temp;
        temp = head;
        h1 = h2 = cur1 = cur2 = NULL;
        while(temp!=NULL){
            if(temp->val < x){
                if(h1==NULL){
                    h1 = temp;
                    cur1 = temp;
                }else{
                    cur1->next = temp;
                    cur1 = cur1->next;
                }
            }else{
                if(h2 == NULL){
                    h2 = temp;
                    cur2 = temp;
                }else{
                    cur2->next = temp;
                    cur2 = cur2->next;
                }
            }
            temp = temp->next;
        }
        if(h1==NULL){
            h1 = h2;
        }else{
            cur1->next = h2;
        }
        if(h2!=NULL)
            cur2->next = NULL;
        
        
        return h1;
    }
};