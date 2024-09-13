#include <iostream>
using namespace std;

class T_Node
{
	public:
		char sym;
		T_Node *left;
		T_Node *right;
		T_Node(char c)
    	{
        	sym=c;
     	}
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

class Exp_Tree
{
	string postfix, prefix, infix;
	T_Node *root;
	Stack S;
			
	public:
		void Create_Postfix();
		void Create_Prefix();
		int Priority(char op);
		void Inorder_Recursive(T_Node*root);
		void Inorder_Non_recursive(T_Node*root);
		void Preorder_Recursive(T_Node*root);
		void Preorder_Non_recursive(T_Node*root);
		void Postorder_Recursive(T_Node*root);
		void Postorder_Non_recursive(T_Node*root);
};
	
int Exp_Tree :: Priority(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}	
		
void Exp_Tree :: Create_Postfix()
{
    // postfix = " ";
	cout<<"\n=============================================================================================\n";
	cout<<"\n >> Enter the Postfix Expression :: ";
    cin>>postfix;
    
    for(int i=0;i<postfix.length();i++)
    {
        root = new T_Node(postfix[i]);
        root->left = NULL;
        root->right = NULL;
        
        if ((postfix[i] <= 'z' && postfix[i] >= 'a') || (postfix[i] <= 'Z' && postfix[i] >= 'A'))
        {
            S.Push(root);
        }
        
        else
        {
            if(Priority(postfix[i]))
            {
                root->right = S.Pop();
                root->left = S.Pop();
                S.Push(root);
            }
        }
    }
    root = S.Pop();
    
    cout<<"\n >>> Recursive Traversal Of Expression Tree :- \n"<<endl;
    cout<<" 1]  Inorder Traversal   ::  ";
    Inorder_Recursive(root);
    cout<<endl;
    cout<<" 2]  Preorder Traversal  ::  ";
    Preorder_Recursive(root);
    cout<<endl;
    cout<<" 3]  Postorder Traversal ::  ";
    Postorder_Recursive(root);
    cout<<endl;

    cout<<"\n >>> Non Recursive Traversal Of Expression Tree :- \n"<<endl;
    cout<<" 1]  Inorder Traversal   ::  ";
    Inorder_Non_recursive(root);
    cout<<endl;
    cout<<" 2]  Preorder Traversal  ::  ";
   	Preorder_Non_recursive(root);
    cout<<endl;
    cout<<" 3]  Postorder Traversal ::  ";
  	Postorder_Non_recursive(root);
    cout<<endl;
    		cout<<"\n============================================================================================="<<endl;
}

void Exp_Tree :: Create_Prefix()
{
    // prefix = " ";
	cout<<"\n=============================================================================================\n";
    cout<<"\n >> Enter the Prefix Expression :: ";
    cin>>prefix;

    for(int i = prefix.length()-1 ; i>=0 ; i--)
    {
        root = new T_Node(prefix[i]);
        root->left = NULL;
        root->right = NULL;
        
        if((prefix[i] >= 'a' && prefix[i] <= 'z')||(prefix[i] >= 'A' && prefix[i] <= 'Z'))
        {
            S.Push(root);
        }
        
        else
        {
            if(Priority(prefix[i]))
            {
                root->left = S.Pop();
                root->right = S.Pop();
                S.Push(root);
            }
        }
    }
    root = S.Pop();
    
    cout<<"\n >>> Recursive Traversal Of Expression Tree :- \n"<<endl;
    cout<<" 1]  Inorder Traversal   ::  ";
    Inorder_Recursive(root);
    cout<<endl;
    cout<<" 2]  Preorder Traversal  ::  ";
    Preorder_Recursive(root);
    cout<<endl;
    cout<<" 3]  Postorder Traversal ::  ";
    Postorder_Recursive(root);
    cout<<endl;

    cout<<"\n >>> Non Recursive Traversal Of Expression Tree :- \n"<<endl;
    cout<<" 1]  Inorder Traversal   ::  ";
   	Inorder_Non_recursive(root);
    cout<<endl;
    cout<<" 2]  Preorder Traversal  ::  ";
   	Preorder_Non_recursive(root);
    cout<<endl;
    cout<<" 3]  Postorder Traversal ::  ";
  	Postorder_Non_recursive(root);
    cout<<endl;
    cout<<"\n============================================================================================="<<endl;
}

void Exp_Tree :: Inorder_Recursive(T_Node*p)
{
    if(p != NULL)
    {
    	Inorder_Recursive(p->left);
    	cout<<p->sym;
    	Inorder_Recursive(p->right);
    }
}

void Exp_Tree :: Preorder_Recursive(T_Node*p)
{
    if(p != NULL)
    {
        cout<<p->sym;
        Preorder_Recursive(p->left);
        Preorder_Recursive(p->right);
    }
}

void Exp_Tree :: Postorder_Recursive(T_Node*p)
{
    if(p != NULL){
        Postorder_Recursive(p->left);
        Postorder_Recursive(p->right);
        cout<<p->sym;
    }
}

void Exp_Tree :: Inorder_Non_recursive(T_Node*p)
{
    while(p != NULL || S.Empty() == false)
    {
        while(p!=NULL)
        {
            S.Push(p);
            p = p->left;
        }
        //p = S.Get_Top();
        p = S.Pop();
        cout<<p->sym;
        p = p->right;
    }
}

void Exp_Tree :: Preorder_Non_recursive(T_Node*p)
{
    if(p == NULL)
    {
        return;
    }
    S.Push(p);

    while(S.Empty() == 0)
    {
        p = S.Get_Top();
        cout<<p->sym;
        p = S.Pop();

        if(p->right)
        {
            S.Push(p->right);
        }    
        if(p->left)
        {
            S.Push(p->left);
        }
            
    }
}

void Exp_Tree :: Postorder_Non_recursive(T_Node*p)
{
    if(p == NULL)
    {
        return;
    }
    else
    {
        Stack S1,S2;
        S1.Push(p);
        T_Node*Node;
    
        while(!S1.Empty())
        {
            Node = S1.Pop();
            S2.Push(Node);

            if(Node->left)
            {
                S1.Push(Node->left);
            }
            if(Node->right)
            {
                S1.Push(Node->right);
            }
        }

        while(!S2.Empty())
        {
            Node = S2.Pop();
            cout<<Node->sym;
        }
    }
}

int main()
{
    int choice;
    Exp_Tree obj;

    cout<<"\n \t\t\t =========================================== \n";
	cout<<" \t\t\t || ASSIGNMENT OF BINARY TREE TRAVERSAL   || \n";
	cout<<" \t\t\t =========================================== \n\n";

    while(true)
    {
 		cout<<"\n=============================================================================================\n";
        cout<<"\n \t\t\t =========================== \n";
		  cout<<" \t\t\t || TREE TRAVERSAL MENU   || \n";
		  cout<<" \t\t\t =========================== \n\n";
cout<<"1] Create Tree From Postfix Expression \t 2] Create Tree From Prefix Expression\n\n3] Exit Program  \n\n >> Enter your choice :: ";
        cin>>choice;
		cout<<"\n=============================================================================================\n";
        
        switch(choice)
        {
            case 1:
                obj.Create_Postfix(); 
                break;
            case 2:
                obj.Create_Prefix();
                break;
        }

        if(choice==3)
        {
			cout<<"\n \t -----> Program Exited Successfully --> "<<endl;
			cout<<"\n=============================================================================================\n\n";
            break;
        }
    }
    return 0;
}
		
		
		

