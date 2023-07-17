class Solution
{
    public:
        ListNode* reverseList(ListNode *head)
        {
            if (!head) return NULL;
            stack<ListNode*> st;
            ListNode *t = head;
            ListNode *last = head;
            while (t != NULL)
            {
                st.push(t);
                last = t;
                t = t->next;
                last->next = NULL;
            }
            head = st.top();
            last = head;
            last->next = NULL;
            st.pop();
            while (!st.empty())
            {
                auto it = st.top();
                st.pop();
                last->next = it;
                last = it;
                it->next = NULL;
            }
            return head;
        }
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *t1 = reverseList(l1);
        ListNode *t2 = reverseList(l2);
        bool carry = false;
        ListNode *head = new ListNode();
        if (t1->val + t2->val > 9)
        {
            head->val = ( t1->val + t2->val )%10;
            carry = true;
        }
        else head->val = t1->val + t2->val;
        t1 = t1->next;
        t2 = t2->next;
        ListNode *last = head;
        while (t1 != NULL and t2 != NULL)
        {
            ListNode *t = new ListNode();

            if (carry==false)
            {
                if (t1->val + t2->val > 9)
                {
                    t->val = ( t1->val + t2->val)%10;
                    carry = true;
                }
                else{
                    t->val = t1->val + t2->val;
                }
            }else{
                if (t1->val + t2->val +1 > 9)
                {
                    t->val = ( t1->val + t2->val +1 )%10;
                }
                else{
                    t->val = t1->val + t2->val +1;
                    carry=false;
                }
            }
            last->next=t;;
            last=t;
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1!=NULL){
            ListNode *t = new ListNode();
            // if(carry)cout<<"TRUE"<<"*************"<<endl;
            if(carry==false){
                    t->val = t1->val;
            }else{
                if (t1->val+1 > 9)
                {
                    t->val = ( t1->val + 1)%10;
                }
                else{
                    t->val = t1->val + 1;
                    carry=false;
                }
            }
            last->next=t;
            last=t;
            t1 = t1->next;
        }
        while(t2!=NULL){
            ListNode *t = new ListNode();
            if(carry==false){
                    t->val = t2->val;
            }else{
                if (t2->val+1 > 9)
                {
                    t->val = ( t2->val + 1 )%10;
                }
                else{
                    t->val = t2->val + 1;
                    carry=false;
                }
            }
            last->next=t;
            last=t;
            t2 = t2->next;
        }
        if(carry){
            ListNode* t=new ListNode();
            t->val=1;
            last->next=t;
            last=t;
        }
        return reverseList(head);
    }
};