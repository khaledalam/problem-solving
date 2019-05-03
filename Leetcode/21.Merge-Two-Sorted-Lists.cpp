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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* root;
        ListNode ** walker = &root;
        
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                *walker = l1;
                l1 = l1 -> next;
            }else {
                *walker = l2;
                l2 = l2 -> next;
            }
            walker = &((*walker)->next);
        }
        
        if(l1 != NULL){
            *walker = l1;
        }else {
            *walker = l2;
        }
        
        return root;
    }
};
