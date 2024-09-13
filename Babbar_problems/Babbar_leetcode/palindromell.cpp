#include<iostream>
using namespace std;
ListNode* reverselist(ListNode* head){
        ListNode* curr=head;
        ListNode* prev = NULL;
        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;            
        }
        return prev;
    }

int main()
{
    List
    return 0;
}