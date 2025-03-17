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
    class compare{
        public:
        bool operator()(ListNode* a, ListNode*b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        for(int i=0;i<lists.size();i++){
            ListNode* listhead = lists[i];
            if(listhead!=NULL){
                pq.push(listhead);
            }
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!pq.empty()){
            ListNode* topnode = pq.top();
            pq.pop();
            if(head==NULL){
                head = topnode;
                tail=topnode;
                if(tail->next!=NULL){
                    pq.push(tail->next);
                }
            }
            else{
                tail->next = topnode;
                tail = topnode;
                if(tail->next!=NULL){
                    pq.push(tail->next);
                }
            }
        }
        return head;
        
    }
};