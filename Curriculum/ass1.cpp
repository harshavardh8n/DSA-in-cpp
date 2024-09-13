#include<iostream>
using namespace std;

struct student{
	string name;
	int roll_no;
	float SGPA;
};

class StudentInfo{
		struct student stud[100];
		int n;
		public:
		int ret_n();
		void getdata();
		void BubSort();
		void InSort();
		void search_SGPA();
		void bisearch_Name();
		int quick(int left,int right);
	    int partition(int left,int right);
		void display();
		void display_3();
		
		};
int StudentInfo::ret_n(){
	return n;
	}
void StudentInfo::getdata(){
	int i;
	cout<<"Student database of SE IT class"<<endl;
	cout<<"Enter number of student :";
	cin>>n;
	for(i=0;i<n;i++){
	cout<<"Enter  information of student Number "<<(i+1)<<endl;
	cout<<"Enter roll no of student :";
			cin>>stud[i].roll_no;
			cout<<"Enter name of student :";
			cin>>stud[i].name;
			cout<<"Enter the SGPA of student :";
			cin>>stud[i].SGPA;
		}	
    }
void StudentInfo::BubSort(){
	cout<<"Data Sorted According to Roll Number using Bubble Short "<<endl;
	int i,j;
	struct student temp;
	for(i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(stud[j].roll_no>stud[j+1].roll_no){
                temp=stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=temp; 
            }
        } 
}
}
void StudentInfo::InSort(){
	cout<<"Data Sorted According Name using Insertion Short "<<endl;
	int k,i,j;
	struct student temp;
	for(i=0;i<(n-1);i++){
		temp=stud[i+1];
		for(j=i+1;j>0;j--)
			{
		 if(stud[j].name<stud[j-1].name)
		 	 {
				stud[j]=stud[j-1];
				stud[j-1]=temp;
				}
			}
	}
}
void StudentInfo::bisearch_Name()
	{
	int i,j;
	student temp;
	for(i=0;i<n-1;i++)
	{
		temp = stud[i+1];
		j = i;
		
		while(stud[j].name>stud[i+1].name && j>=0)
		{
			stud[j+1] = stud[j];
			stud[j] = temp;
			j--;
		}
	}

	int flag=0,left=0,right=(n-1),mid=0;
	string check;
	cout<<"Enter the Name of the Student to Search = ";
	cin>>check;
	
	cout<<"The Students are : "<<endl;
	while(left<=right)
	{
		mid=(left+right)/2;
		cout<<"____________________________________________________"<<endl;
		cout<<"Roll no. ||	Name	||	 SGPA "<<endl;  
		cout<<"____________________________________________________"<<endl; 
		if(stud[mid].name==check)
		{
			cout<<stud[i].roll_no;
        	cout<<"		";
        	cout<<stud[i].name;
        	cout<<"		";
        	cout<<stud[i].SGPA<<endl;
        	cout<<"------------------------------------------------"<<endl;
			flag=1;
		}
		if(stud[mid].name>check)
		{
			right=mid-1;
		}
		else
		{
			left=mid+1;
		}
	}
	if(flag==1)
	{
		cout<<" There is no student with this Name "<<endl<<endl;
	}
	}
void StudentInfo::search_SGPA(){
	int flag=0,i;
	float check;
	cout<<"Enter the SGPA of the Student to Search = ";
	cin>>check;
	if(check<=10 && check>=0){
	cout<<"The Students are : "<<endl;
	cout<<"SGPA ||	Roll no.	||	Name"<<endl;
	for(i=0;i<n;i++)
	{
		if(check==stud[i].SGPA)
		{
		if(flag==1){
			cout<<stud[i].SGPA;
        	cout<<"		";
			cout<<stud[i].roll_no;
			cout<<"		";
        	cout<<stud[i].name<<endl;
      	 cout<<"----------------------------------------------------"<<endl;

			flag++;
		}	
	}
	}
	if(flag==1)
		{
			cout<<" There is no student with this SGPA "<<endl<<endl;
		}
	cout<<endl;
	}
	else{
	cout<<"Enter SGPA Between 0 to 10 "<<endl;
	}
	

}
int StudentInfo::partition(int left,int right){
	int pivote=stud[right].SGPA;
	int i=left;
	int j=right-1;
	while(i<=j)
	  {
	  while(stud[i].SGPA<pivote && i<right)
	   {
	    i=i+1;
	   } 
	  while(j>=0 && stud[j].SGPA>pivote)
	   {
	   j=j-1;
	   }
	  if(i<j)
	  {
	  swap(stud[i],stud[j]);
	  }
	   }
	   swap(stud[i],stud[right]);
	   return i;
	}
int StudentInfo::quick(int left,int right){
	if(left>=right)
	  {
	  return 0;
	  }
	else
	  {
int	p=partition(left,right);
	  quick(left,p-1);
	  quick(p+1,right);
	  }
	  return 0;
	}	
void StudentInfo::display(){
	int i;
	cout<<"____________________________________________________"<<endl;
	cout<<"Roll no. ||	Name	||	 SGPA "<<endl;  
	cout<<"____________________________________________________"<<endl; 
    for(i=0;i<n;i++)
    {
        cout<<stud[i].roll_no;
        cout<<"		";
        cout<<stud[i].name;
        cout<<"		";
        cout<<stud[i].SGPA<<endl;
        cout<<"------------------------------------------------"<<endl;      
    } 
}
void StudentInfo::display_3()
{
	cout<<"____________________________________________________"<<endl;
	cout<<"First 10 Toppers of class are  "<<endl;
	cout<<"____________________________________________________"<<endl;
	int i,j;
	cout<<"SGPA ||	Roll no.	||	Name"<<endl;
	for(i=14;i>5;i--)
	{
		cout<<stud[i].SGPA;
        cout<<"		";
		cout<<stud[i].roll_no;
		cout<<"		";
        cout<<stud[i].name<<endl;
        cout<<"----------------------------------------------------"<<endl;
	}
	cout<<endl<<endl;
}

int main(){
	cout<<"\n****************** Program to Display the Data of the Students ************* "<<endl;
	int choice;
	StudentInfo obj;
	do{
	cout<<"****** Main Menu ******"<<endl;
	cout<<"1.Get Student Data "<<endl;
	cout<<"2.Display Student Data "<<endl;
	cout<<"3.Data Sorted According to Roll No using Bubble Sort"<<endl;
	cout<<"4.Data Sorted According to Alphabetically using Insrtion Sort  "<<endl;
	cout<<"5.Arrange the list of first 10 topers using Quick Sort "<<endl;
	cout<<"6.Search Student According to SGPA"<<endl;
	cout<<"7.Search Student According to Name "<<endl;
	cout<<"8.Enter for Exit "<<endl;
	cout<<"Enter Your Choice :";
	cin>>choice;
	switch(choice){
	case 1: obj.getdata();
			break;
	case 2:if(obj.ret_n()>0)
			{
	 		obj.display();
			}
			else
			{
			cout<<"First You Entered Data Then you can perform next operation"<<endl;
			}
			break;
	case 3:if(obj.ret_n()>0)
			{
			obj.BubSort();
			}
			else
			{
			cout<<"First You Entered Data Then you can perform next operation"<<endl;
			}
			break;
	case 4:if(obj.ret_n()>0)
			{
			obj.InSort();
			}
			else
			{
			cout<<"First You Entered Data Then you can perform next operation"<<endl;
			}
			break;
	case 5:if(obj.ret_n()>0)
			{
			obj.quick(0,obj.ret_n());
		   obj.display_3();
		   }
		   else
			{
			cout<<"First You Entered Data Then you can perform next operation"<<endl;
			}
			break;
	case 6:if(obj.ret_n()>0)
			{
			obj.search_SGPA();
			}
			else
			{
			cout<<"First You Entered Data Then you can perform next operation"<<endl;
			}
			break;
	case 7:if(obj.ret_n()>0)
			{
			obj.bisearch_Name();
			}
			else
			{
			cout<<"First You Entered Data Then you can perform next operation"<<endl;
			}
			break;
	default:"Exit  Thank-You";
 	}
 	}while(choice<8);
 	return 0;
 	}

