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
        
        vector<int>res;
        
        ListNode* nextt = head;
        ListNode* walker = head;
        int currentVal = head->val;
        
        while(nextt != NULL){
        
            while(walker != NULL && walker->val <= currentVal){
                walker = walker->next;
            }
            
            res.push_back( (walker != NULL ? walker->val : 0) );
            
            nextt = nextt->next;
            walker = nextt;
            if(nextt != NULL)currentVal = nextt->val;
        }
        
        return res;
        
        
    }
};
