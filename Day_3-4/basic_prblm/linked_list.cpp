// Implementing Linked List Using struct and class to get familiar with the syntax
//
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int x=-1){
		this->data=x;
		this->next=nullptr;
	}
	void insertNext(int x){
		Node* temp=this;
		while(temp->next!=nullptr)temp=temp->next;
		temp->next=new Node(x);
		
	}

	void printList(){	
		Node* temp=this;
		cout<<"The printed List is:\n";
		while(temp!=nullptr){
			cout<<temp->data<<",";
			temp=temp->next;
		}
		cout<<endl;

	}
	Node* reverseList(){
		Node* curr=this;
		Node* next=this->next;
		Node* prev=nullptr;

		while(curr!=nullptr){
			curr->next=prev;
			prev=curr;
			curr=next;
			if(curr!=nullptr)
			next=curr->next;
		}
		return prev;

	}
};

int main(){
	
	Node* head=new Node(5);
	head->insertNext(12);
	Node *t=head->next;
	int x;
	while(x!=-1){
		cout<<"Enter the value of the node to be inserted\n";
		cin>>x;
		if(x%2)head->insertNext(x);
		else t->insertNext(x);
	}

	t->printList();
	head->printList();
	head = head->reverseList();
	head->printList();
	t->printList();

}
