#include<iostream>
#include<iomanip>
using namespace std;

class Queue
{
    public:
		int queue[10],front,rear,number,size=10;
		Queue()
		{
			front=-1,rear=-1;
		}
		void enqueue();
		void dqueue();
		void display();
};

void Queue::enqueue()
{
	if(rear==size-1)
	{
		cout<<" Queue is full. "<<endl;
	}
	else
	{
		if(front ==-1)
		{ 
			front=0; 
		}
		rear=rear+1;
		cout<<" Enter the number to insert = ";
		cin>>number;
		queue[rear]=number;	
	}
}

void Queue::dqueue()
{
	if(front==rear==-1 || front>rear)
	{
		cout<<" Queue is empty. "<<endl;
	}
	else
	{
		cout<<" No. "<<queue[front]<<" is deleted from the Queue"<<endl;
		queue[front]=6666666;
		front=front+1;
	}
}	

void Queue::display()
{
	int col_width = 5;
	cout << left;
	cout<<"________________________________________________________________"<<endl;
	cout<<" Index Value   ";
	for(int i=0;i<=rear;i++)
	{
		cout<< setw(col_width) <<i;
	}
	cout<<"\n________________________________________________________________"<<endl;
	cout<<" Queue Value   ";
	for(int i=0;i<=rear;i++)
	{
		if(queue[i]==6666666)
		{
			cout<< setw(col_width) <<"-";
		}
		else
		{
			cout<< setw(col_width) <<queue[i];
		}
	}
	cout<<"\n________________________________________________________________"<<endl;
    cout<<"The value of front is "<<front<<endl;
    cout<<"\n________________________________________________________________"<<endl;
    cout<<"The value of rear is "<<rear<<endl;
    cout<<"\n________________________________________________________________"<<endl;
}

int main()
{
	Queue obj;
	int choice;
	cout<<"\n ***** IMPLEMENTATION OF CIRCULAR QUEUE USING ARRAY ***** "<<endl;
	do
	{
		cout<<"\n <<< Menu Menu  >>> "<<endl;
		cout<<" 1. Insert a element in queue \n 2. Delete a element in queue\n 3. Display the Circular Queue. \n 4. Exit the program. "<<endl;
		cout<<"\n Enter the Operation to be Performed = ";
		cin>>choice;
		cout<<endl;
		switch(choice)
		{
			case 1:
			obj.enqueue();
            obj.display();
			break;
			case 2:
			obj.dqueue();
            obj.display();
			break;
			case 3:
			obj.display();
			break;
            default:cout<<" >>>>> Program Exited Successfully >>>>> \n"<<endl;
            break;
		}
	}while(choice<4);
	return 0;
}
