#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* front=NULL;
node* rear=NULL;

bool isEmpty()
{
	if(front==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void enqueue(int x)
{
	if(isEmpty())
	{
		node* ptr= new node();
		ptr->data=x;
		ptr->next=ptr;
		front=ptr;
		rear=ptr;
		cout<<"enqueueed !"<<endl;
	}
	else
	{
		
		node *ptr=new node();
		ptr->data=x;
		ptr->next=rear->next;
		rear->next=ptr;
		rear=rear->next;
		cout<<"enqueueed !"<<endl;
	}
}
void dequeue()
{
	if(isEmpty())
	{
		cout<<"sorry cant dequeue ,already empty "<<endl;
	}
	else
	{
		if(front==rear&&front!=NULL)
		{
			front=NULL;
			rear=NULL;
		}
		else
		{
			front=front->next;
			cout<<"dequeueped !"<<endl;
		}
	}
}
void display()
{
	if(isEmpty())
	{
		cout<<"sorry cant display the linked list is empty "<<endl;
	}
	else
	{
		node* ptr=front;
		do
		{
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}while(ptr!= rear->next);
		}
}
int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	display();
	cout<<endl;
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	cout<<endl;
	display();
}
