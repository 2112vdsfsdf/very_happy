
#include<iostream>
using namespace std;
struct node
{
	node* prev;
	int data;
	node* next;
};

node* head=NULL;
node* curr=NULL;
void insert(int x)
{
	if(head==NULL&&curr==NULL)
	{
		node* ptr=new node();
		ptr->prev=NULL;
		ptr->data=x;
		ptr->next=NULL;
		head=ptr;
		curr=ptr;
	}
	else if(head!=NULL&&curr==NULL)
	{
		node* ptr=new node();
		ptr->prev=NULL;
		ptr->data=x;
		ptr->next=head;
		head=ptr;
		curr=ptr;
	}
	else
	{
		node* ptr= new node();
		ptr->data=x;
		ptr->next=curr->next;
		ptr->prev=curr;
		curr->next=ptr;
		curr=curr->next;
	}
}
void back()
{
	if(head==NULL&&curr==NULL)
	{
		cout<<"cant go back further "<<endl;
	}
    else 
    {
    	
    	curr=curr->prev;
	}
}
void forward()
{
	if(curr->next==NULL)
	{
		cout<<"cannot go ahead as already at the last of the linked list "<<endl;
	}
	else
	{
		curr=curr->next;
	}
}
void Delete()
{
	if(head==NULL&&curr==NULL)
	{
		cout<<"sorry cant delete as no node is there"<<endl;
	}
	else if (head!=NULL&&curr==NULL)
	{
		cout<<"sorry cannot delete as the curr is at the NUll"<<endl;
	}
	else
	{
	   curr->prev->next=curr->next;
	   curr->next->prev=curr->prev;
	   curr=curr->prev;
	}
}

void display()
{
	node* pointer=head;
	while(pointer!=NULL)
	{
		cout<<pointer->data<<" ";
		pointer=pointer->next;
	}
}

int main()
{
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	display();
	back();
	back();
	back();
	back();
	back();
	back();
	insert(0);
	cout<<endl;
	display();
}
