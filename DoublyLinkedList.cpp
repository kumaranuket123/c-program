#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* prev;
	Node* next;

	Node(int d){
		data=d;
		prev=NULL;
		next=NULL;
	}

};

void insertAtHead(Node* &head,int data){
	Node* temp= new Node(data);
	temp->next=head;
	head->prev=temp;
	head=temp;
}

void insertAtTail(Node* &tail, int data){
	Node* temp= new Node(data);
	temp->prev= tail;
	tail->next=temp;
	tail=temp;
}

void insertAtPosition(int position, Node* &head, Node* &tail, int data){
	if(position==0){
		insertAtHead(head,data);
		return;
	}
	Node* temp= head;
	int cnt=1;
	while(temp!=NULL){
		temp=temp->next;
		cnt++;
	}
	
}


void print(Node* head){
	Node* temp=head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}


int main(){
	Node* node1=new Node(10);
	Node* head=node1;
	Node* tail=node1;
	print(head);

	insertAtHead(head,20);
	print(head);

	insertAtTail(tail,30);
	print(head);

	insertAtPosition(2,head,tail,25);
	print(head);

	cout<<"head= "<<head->data<<endl;
	cout<<"tail= "<<tail->data<<endl;

}