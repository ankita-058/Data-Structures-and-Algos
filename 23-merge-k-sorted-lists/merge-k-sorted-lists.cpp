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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minH;
        for(ListNode* list : lists){
            if(list != NULL){
                minH.push(list);
            }
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(!minH.empty()){
            ListNode* smallest = minH.top();
            minH.pop();
            tail->next = smallest;
            tail = tail->next;
            if(smallest->next != NULL){
                minH.push(smallest->next);
            }
        }
        return dummy.next;
    }
};