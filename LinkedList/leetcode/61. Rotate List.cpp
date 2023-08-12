class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode *temp, *i, *tail;
        temp = head, tail=NULL;
        while(temp != NULL){    // counting element
            tail = temp;
            temp = temp -> next;
            n++;
        }
        k = k>0 ? n-k : k;      // checking k=0
        k = n>0 ? k%n : k;      // finding absolute rotation
        if(head!=NULL && k>0){
            
            temp = head;
            while(k>1){
                temp = temp->next;      // traversing new last-node 
                k--;
            }
            tail->next = head;          // connecting last node to head
            head = temp->next;          // assigning new head
            temp->next = NULL;          // assigning end after new last-node
        }
        return head;
    }
};