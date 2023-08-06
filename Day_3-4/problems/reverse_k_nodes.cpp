#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int x){
		this->data=x;
		this->next=nullptr;
	}
};

struct LinkedList{
	Node* head;

	LinkedList(){
		head=nullptr;
	}

	void insert(int data){
		if(head==nullptr)head=new Node(data);
		else{
			Node* temp=head;
			while(temp->next!=nullptr){
				temp=temp->next;
			}
			temp->next=new Node(data);
			delete(temp);

		}
	}

	void printList(){
		Node* temp=head;
		while(temp!=nullptr){
			cout<<temp->data<<(temp->next==nullptr?"!!\n":" -> ");
			
			temp=temp->next;
		}
		delete(temp);
	}

	void rev_list(){
		Node* prev=nullptr;
		Node* curr=head;
		Node* next=nullptr;
		while(curr!=nullptr){
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		head=prev;
		delete(prev);
		delete(curr);
		delete(next);
	}

	void rev_every_k_node(int k){
		int l=0;
		Node *temp=head;
		while(l<k&&temp->next!=nullptr){
			
		}
	}
};

int main(){
	LinkedList ll;
	ll.insert(5);
	ll.insert(10);
	ll.printList();
	ll.rev_list();
	ll.printList();
	
}
