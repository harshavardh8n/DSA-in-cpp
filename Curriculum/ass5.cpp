#include<iostream>
using namespace std;
class T_Node
{
	public:
		int data;
		T_Node *left;
		T_Node *right;
};

class S_Node
{
	public:
    	int No;
    	T_Node*address;
    	S_Node*next;
};		

class Stack
{
	public:
		S_Node *top;
		
		Stack()
		{
			top = NULL;
		}
		void Push(T_Node*);
    	T_Node*Pop();
    	T_Node*Get_Top();
        int Empty(); 
};

void Stack :: Push(T_Node*root)
{
	S_Node*temp;
	temp = new S_Node;
   	temp->address = root;
   	
	if(top == NULL)
	{
		temp->next = NULL;
        top = temp;	
	}
	
	else
	{
		temp->next = top;
        top = temp;
	}	
}		
		
T_Node*Stack :: Pop()
{		
	T_Node *A;	
		
	if(top == NULL)
	{
		// cout<<" Stack Underflow ";
    	// cout<<"\n=============================================================================================";
    	return 0;
	}	
	else	
	{
		A = top->address;
		top = top->next;
		return (A);
	}	
}		
	
T_Node*Stack :: Get_Top()
{
	T_Node *A;	

    if (top != NULL)
    {
        A = top->address;
        return (A);
    }
    return NULL;
}	

int Stack :: Empty()
{
    if (top == NULL)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
class BST{
T_Node *root;
	public:
		BST(){
		root=NULL;
	
	}
		void Create();
		void insert();
		void In_display();
		void pre_display();
		void post_display();
		void deletenode();
};

void BST::Create(){
	


}
int main(){




	return 0;
}
