#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

    node(int d){
        data=d;
        next =NULL;
    }

    //destructor
    ~node(){
        int value=this->data;
        //free memory
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }
};



void insertAtHead(node* &head, int data){
    node* temp= new node(data);
    temp->next=head;
    head= temp;
}


void insertAtTail(node* &tail,int data){
    node* temp= new node(data);
    tail->next=temp;
    tail=temp;
}


void insertAtPosition(node* &head,node* &tail,int position,int data){
    if(position==0){
        insertAtHead(head,data);
        return;
    }
    node* temp=head;
    for(int i=1;i<position;i++){
        temp=temp->next;
    }
    if(temp->next==NULL){
        insertAtTail(tail,data);
        return;
    }
    node* insertNode = new node(data);
    insertNode->next=temp->next;
    temp->next= insertNode;
}


void deleteAtPosition(int position,node* &head,node* &tail){
    //deleting start node
    if(position==1){
        node* temp=head;
        head=head->next;
        //memory free
        temp->next=NULL;
        delete temp;
    }
    else{
        //deleting any node
        node*curr=head;
        node*prev=NULL;
        
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        //for last node
        if(curr->next==NULL){
            tail=prev;
        }      
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}



void print(node* &head){
    node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}



int main(){
    node *node1= new node(10);
    node* head=node1;
    node* tail=node1;
    cout<<node1->data<<endl;

    insertAtHead(head,20);
    print(head);

    insertAtTail(tail,5);
    print(head);

    insertAtPosition(head,tail,3,225);
    print(head);
    cout<<"head= "<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;

    deleteAtPosition(4,head,tail);
    print(head);

    cout<<"head= "<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;
    return 0;
}