#include <iostream>
using namespace std;


class Node{

    public:
        int data;
        Node* next;

    Node(int val){
        data = val;
        next=NULL;
        };


};

    Node* recursive_reverse(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* chotahead = recursive_reverse(head->next);
        head->next->next = head;
        head->next=NULL;
        return chotahead;
    }
    void iterative_reverselist(Node* &head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next;
        while(curr!=NULL){
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
    void addNodeAtTail(Node* &head,int val){
        Node* newnode = new Node(val);
        Node* temp = head;
        if(head==NULL){
            head=newnode;
            return;
        }
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newnode;

    }

    void display(Node* &head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" => ";
            temp=temp->next;

        }
        cout<<"NULL";
        cout<<endl;
        
    }

    void addAtHead(Node* &head,int val){
        Node* newnode = new Node(val);
        if(head==NULL){
            head=newnode;
            return;
        }
        Node* temp = head;
        head=newnode;
        newnode->next=temp;

    }

    void deleteAtTail(Node* &head){
        if(head==NULL){
            cout<<"list empty";
            return;
        }
        else if(head->next==NULL){
            head = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;

        }
        // cout<<"element is"<<temp->data;
        delete temp->next;
        temp->next=NULL;
    }

    void deleteAKey(Node* &head, int key){
        Node* temp = head;
        while(temp->next->data!=key){
            temp = temp->next;
        }
        // cout<<"element is"<<temp->data;
        Node* temp2 = temp->next->next;
        delete temp->next;
        temp->next = temp2;
    }

int main(){
    Node* head = new Node(0);
    // cout<<head->data;
    addNodeAtTail(head,1);
    addNodeAtTail(head,4);
    addNodeAtTail(head,77);
    addNodeAtTail(head,9);
    addNodeAtTail(head,10);
    display(head);
    cout<<endl;
    // addAtHead(head,5);
    // display(head);
    // deleteAtTail(head);
    // display(head);
    // deleteAKey(head,101);
    // display(head);
    // iterative_reverselist(head);
    head=recursive_reverse(head);
    display(head);
    // addNodeAtTail(head,7);
    // addNodeAtTail(head,56);
    // addNodeAtTail(head,656);
    // display(head);
    // cout<<endl;
    // addNodeAtTail(head,568);
    // addNodeAtTail(head,567);
    // display(head);
    // cout<<head->next->data;




    return 0;
}