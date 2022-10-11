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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
       vector<int> v;
        ListNode*temp=head->next;
        
        while(temp!=0)
        {
            if(temp->val==0)
            {
                v.push_back(sum);
                sum=0;             
            }
            else
            {
                sum+=temp->val;
            }
            temp=temp->next;
        }
        
        int siz=v.size();
   
        temp=head;
        
        for(int i=0;i<siz;i++)
        {
            temp->val=v[i];
            temp=temp->next;
        }
        temp=head;
        for(int i=0;i<siz-1;i++)
        {
            temp=temp->next;
        }
        temp->next=0;
        return head;
        
    }
};
