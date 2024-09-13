#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
template<class T>
class node
   {
    public:
     T data;
     node<T> *next;
   };
template<class T>
class stack
{
    node<T> *top;
    
    T x;
  public:
      stack()
      {
         top= NULL;
      }
     T empty();
     void push(T x);
     T pop();
     T Get_Top();
};
template <class T>
T stack<T>::empty()
      {
         if(top==NULL)
         {
            return(1);
         }
         else
         {
            return(0);
         }
     }
template <class T>
void stack<T>::push(T x)
     {
        node<T> *p;
        p=new node<T>;
        p->data=x;
        p->next=top;
        top=p;
     }
template <class T>
T stack<T>:: pop()
    {
      if(!empty())
      {
          node<T> *p;
          p=new node<T>;
          p=top;
          top=top->next;
          x=p->data;
          delete p;
          return(x);
     }
      else
      {
           cout<<"stack is empty"<<endl;
           return(0);
      }
    }
template <class T>
T stack<T> ::Get_Top()
    {
      if(!empty())
      {
          node<T> *p;
          p=new node<T>;
          p=top;
          //top=top->next;
          x=p->data;
          //delete p;
          return(x);
     }
      else
      {
           cout<<"stack is empty"<<endl;
           return(0);
      }
    }
template <class T>
class expression{
  
public:
 char infix[30],prefix[30],postfix[30];
 stack <int> s;
 T precedence(char x);
 void input();
 void infix_to_prefix(char infix[],char prefix[]);
 void infix_to_postfix(char infix[],char postfix[]);
 void eval_prefix(char prefix[]);
 void eval_postfix(char postfix[]);
 T evaluate(char x,int op1,int op2);
};
template <class T>
void  expression<T>::input(){
   cout<<"\nEnter the infix expression::"<<endl;
   cin>>infix;

}
template <class T>
void expression<T>::infix_to_prefix(char infix[],char prefix[])
{
   int i,j;
   char temp,in1[30];
 cout<<"\n\n After step 1...\nEntered infix is...";
 for(i=0;i<=strlen(infix)-1;i++)
 {
  cout<<infix[i];
 }
   for(i=strlen(infix)-1,j=0;i>=0;i--,j++)
   in1[j]=infix[i];
   in1[j]='\0';
  cout<<"\n\n After step 2...";
 for(i=0;i<=strlen(in1)-1;i++)
 {
  cout<<in1[i];
 }
   for(i=0;in1[i]!='\0';i++)
    {
      if(in1[i]=='(')
          in1[i]=')';
      else
        if(in1[i]==')')
             in1[i]='(';
    }
 cout<<"\n\n After step 3...";
 for(i=0;i<=strlen(in1)-1;i++)
 {
  cout<<in1[i];
 }
 cout<<"\n\n After step 4...";
 cout<<"\n\n Prefix is...";
   infix_to_postfix(in1,prefix);
   for(i=0,j=strlen(prefix)-1;i<j;i++,j--)
   {
     temp=prefix[i];
     prefix[i]=prefix[j];
     prefix[j]=temp;
   }
}
template <class T>
void expression<T>::infix_to_postfix(char infix[],char postfix[])
{
  node<T> *top;
char x;
int i,j;
char token;
j=0;
for(i=0;infix[i]!='\0';i++)
{
  token=infix[i];
  if(isalnum(token))
  {
      postfix[j++]=token;
  }
  else if(token=='(')
     {
       s.push('(');
     }
     else if(token==')')
       {
          while((x=s.pop())!='(')
          {
             postfix[j++]=x;
          }
       }
     else
     {
 x=s.Get_Top();
 while(precedence(token)<precedence(x)&& !s.empty())
         {
            x=s.pop();
            postfix[j++]=x;
         }
       s.push(token);
     }
}
    while(!s.empty())
     {
        x=s.pop();
        postfix[j++]=x;
     }
    postfix[j]='\0';
}
template <class T>

T expression<T>::precedence(char x)
{
   if(x=='(')
   {
      return(0);
   }
   if(x=='+'||x=='-')
   {
       return(1);
   }
   if(x=='*'||x=='/'||x=='%')
   {
     return(2);
   }
   return(3);
}
template <class T>
void expression<T>::eval_prefix(char prefix[])
{
 
  char x;
  int op1,op2,val,i;
  for(i=strlen(prefix)-1;i>=0;i--)
   {
     x=prefix[i];
     if(isalpha(x))
      {
         cout<<"\nEnter the value of "<<x<<":";
         cin>>val;
         s.push(val);
      }
    else
     {
       op1=s.pop();
       op2=s.pop();
       val=evaluate(x,op1,op2);
       s.push(val);
     }
   }
val=s.pop();
cout<<"\nValue of expression is "<<val;
}
template <class T>

T expression<T>::evaluate(char x,int op1,int op2)
{
if(x=='+')
return(op1+op2);
if(x=='-')
return(op1-op2);
if(x=='*')
return(op1*op2);
if(x=='/')
return(op1/op2);
if(x=='%')
return(op1%op2);
if(x=='^')
return(pow(op1,op2));
if(x=='&')
return(op1&op2);
return x;
}
template <class T>

void expression<T>:: eval_postfix(char postfix[])
{
  char x;
  int op1,op2,val,i;
  for(i=0;postfix[i]!='\0';i++)
   {
     x=postfix[i];
     if(isalpha(x))
      {
         cout<<"\nEnter the value of "<<x<<":";
         cin>>val;
         s.push(val);
      }
    else
     {
       op2=s.pop();
       op1=s.pop();
       val=evaluate(x,op1,op2);
       s.push(val);
     }
   }
val=s.pop();
cout<<"\nValue of expression is "<<val;
}

int main()
{
    expression<int> obj;

   int op;
do{cout<<endl;
cout<<endl;
   cout<<"\t<<<<< Menu Menu >>>>> \n\n1)Conversion of Infix to Postfix \n\n2)Evaluation of Postfix \n\n3)Conversuin of Infix to Prefix\n\n4)Evaluation of prefix\n\n5)Exit From  a program \n\nEnter your choice:: ";
   cin>>op;
   cout<<endl;
switch(op)
{
case 1:
   obj.input();
   obj.infix_to_postfix(obj.infix,obj.postfix);
   cout<<endl;
   cout<<"\nPostfix expression is "<<obj.postfix<<endl;
   
break;
  case 2:
  cout<<"\n\nEvaluation of Postfix expression";
  cout<<endl;
   obj.eval_postfix(obj.postfix);
   break;
case 3:
   obj.input();
   obj.infix_to_prefix(obj.infix,obj.prefix);
   cout<<endl;
   cout<<"\nPrefix expression is "<<obj.prefix<<endl;
   cout<<endl;
   
break;
case 4:
cout<<"\n\nEvaluation of Prefix expression";
cout<<endl;
   obj.eval_prefix(obj.prefix);
   break;
case 5:
   cout<<"Program Exited Succesfully Thank-You"<<endl;
   break;
default:cout<<"Enter the valid input"<<endl;
break;
} 
}while(op!=5);
return 0;
}
 
