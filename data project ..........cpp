#include<iostream>
#include<string>
using namespace std;
class student
{
	public:
	string name;
	float gpa,semester_gpa;
	int id;
	string semester;
	string grade;
	int semester_hour;
	int total_hour;
	int earned_hour;
	student*next;
	student*previous;
	student(string name,float gpa,float semester_gpa,int id , string semester,string grade,int semester_hour,int total_hour,int earned_hour)
	{
		this->name=name ;
		this->gpa=gpa ;
		this->semester_gpa=semester_gpa ;
		this-> id=id;
		this->semester=semester ;
		this->grade=grade; 
		this->semester_hour=semester_hour;
		this->total_hour=total_hour;
		this->earned_hour=earned_hour;
		this->next=NULL;
		this->previous=NULL;
	}
};
class linkedlist
{
	string new_name;
	float new_gpa;
	float new_semester_gpa;
	int new_id;
	string new_semester;
    string new_grade;
	int new_semester_hour;
	int new_total_hour;
	int new_earned_hour;
	public:
		student*head;
		int listsize;
		linkedlist()
		{
			head=NULL;
			listsize=0;
		}
		void traversal();
		void insertfirst(string new_name,float new_gpa,float new_semester_gpa,int new_id ,
		 string new_semester,string new_grade,int new_semester_hour,int new_total_hour,int new_earned_hour);
		void insertend(string new_name,float new_gpa,float new_semester_gpa,int new_id, 
		 string new_semester,string new_grade,int new_semester_hour,int new_total_hour,int new_earned_hour);
		void insertafter(string new_name,float new_gpa,float new_semester_gpa,int new_id, 
		 string new_semester,string new_grade,int new_semester_hour,int new_total_hour,int new_earned_hour,int target);
		 void add_at(string new_name,float new_gpa,float new_semester_gpa,int new_id, 
		 string new_semester,string new_grade,int new_semester_hour,int new_total_hour,int new_earned_hour,int target);
		void search(int id);
        void deletbegin();
        void deletatend();
        void deletwhere(int item);
        void getline();
        void sortlist();
        void update_semester_hours(int Id,int new_val);
        void update_gpa(int Id ,float new_val);
        void update_semester_gpa(int Id,float new_val);
        void update_grade(int Id ,string new_val);
        void update_name(int Id,string new_val);
        void update_earned_hours(int Id,int new_val);
        void update_total_hours( int Id,int new_val);
        void display_reverse();
        ~linkedlist()
        {
        	
          	student*temp=head;
			if(head==NULL)
			{
				return;
			}
			while(head!=NULL)
			{
				delete temp;
				head=head->next;
				temp=head;
			}
		}
        
};
 void linkedlist::getline()
 {
        cout<<"enter name of student\n";
		 	cin>>new_name;
		 	cout<<"enter his id\n";
		 	cin>>new_id;
		 	cout<<"enter his gpa\n";
		 	cin>>  new_gpa;
		 	do
			 {
		 	   if(new_gpa>4||new_gpa<0)
				{
					cout<<"incorrect gpa please enter the correct one\n";
					cin>>  new_gpa;
				}	
				else
				{
					break;
				}
			 }while(true);
		 	cout<<"enter his semeser gpa\n";
		 	cin>> new_semester_gpa;
		 	do
			 {
		 	   if(new_semester_gpa>4||new_semester_gpa<0)
				{
					cout<<"incorrect gpa please enter the correct one\n";
					cin>>new_semester_gpa;
				}	
				else
				{
					break;
				}
			 }while(true);
		 	cout<<"enter hisgrade like A orA- and so on \n";
		 	cin>> new_grade;
			 cout<<"enter his earned hour \n";
			 cin>>new_earned_hour;
			 if(new_gpa>=2)
			 {
			 	 new_semester_hour=18;
			 }
		 	 else
		 	 {
		 	 	 new_semester_hour=9;
			 }
			     new_total_hour=144;
			     insertend(new_name,new_gpa,new_semester_gpa,new_id,new_semester,new_grade,new_semester_hour,new_total_hour,new_earned_hour);
    }
void linkedlist::traversal()
{
	student*temp=head;
	while(temp!=NULL)
	{
		cout<<temp->id<<"\t"<<temp->name<<"\t"<<temp->gpa<<"\t"<<temp->semester_gpa<<"\t        "<<temp->grade<<"\t   "<<
		temp->total_hour<<"\t            "<<temp->semester_hour<<"\t            "<<temp->earned_hour<<"\t"<<"\n";
		if(temp->earned_hour==18)
		{
			cout<<"                                                 YOU PASS\n";
			cout<<"                                       intro & calculus &linear1 & critical\n\n";
		}
		else if(temp->earned_hour==36)
		{
			cout<<"                                                 YOU PASS\n";
			cout<<"                                programming1 & physics & linear11 & presentation\n\n";
		}
		else if(temp->earned_hour==54)
		{
			cout<<"                                               YOU PASS\n";
			cout<<"                                       oop & data & logic & managmnet\n\n";
		}
		else if(temp->earned_hour==72)
		{
			cout<<"                                               YOU PASS\n";
			cout<<"                                      oop2 & algorithm & soft & electronics\n\n";
		}
		else if(temp->earned_hour==90)
		{
			cout<<"                                               YOU PASS\n";
			cout<<"                                     oop3 & algorithm2 & soft11 & probability\n\n";
		}
		else if(temp->earned_hour==0) 
		{
			cout<<"                                                           NEW CAMER\n\n";
		}
		else if (temp->earned_hour==144)
		{
			cout<<"                                                              GRADUATED\n\n";
		}
		temp=temp->next;
	}
}
void linkedlist::insertfirst(string new_name,float new_gpa,float new_semester_gpa,int new_id, 
		 string new_semester,string new_grade,int new_semester_hour,int new_total_hour,int new_earned_hour)
{
	student*newnode=new student(new_name, new_gpa, new_semester_gpa,new_id,
		   new_semester, new_grade, new_semester_hour, new_total_hour, new_earned_hour);
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	newnode->next=head;
	head=newnode;
	listsize++;
}
void linkedlist::insertend(string new_name,float new_gpa,float new_semester_gpa,int new_id ,
		 string new_semester,string new_grade,int new_semester_hour,int new_total_hour,int new_earned_hour)
{
	student*newnode=new student(new_name, new_gpa, new_semester_gpa,new_id,
		   new_semester, new_grade, new_semester_hour, new_total_hour, new_earned_hour);
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	 student*temp=head;
	 while(temp->next!=NULL)
	 {
	 	temp=temp->next;
	 }
	temp->next=newnode;
	newnode->next=NULL;
	listsize++;
}
void linkedlist::insertafter(string new_name,float new_gpa,float new_semester_gpa,int new_id,
		 string new_semester,string new_grade,int new_semester_hour,int new_total_hour,int new_earned_hour,int target)
{
student*newnode=new student(new_name, new_gpa, new_semester_gpa,new_id ,
		   new_semester, new_grade, new_semester_hour, new_total_hour, new_earned_hour);
    student*temp=head;
	if(target==listsize)
	{
		this->insertend( new_name, new_gpa, new_semester_gpa,new_id, 
		  new_semester, new_grade, new_semester_hour, new_total_hour, new_earned_hour);
		return;
	}	
	else
	{
		for(int i=0;i<target;i++)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
 	    temp->next=newnode;
	}
	listsize++;
}
void linkedlist::add_at(string new_name,float new_gpa,float new_semester_gpa,int new_id,
		 string new_semester,string new_grade,int new_semester_hour,int new_total_hour,int new_earned_hour,int target)
{
	student*temp=head;
	student*newnode=new student(new_name, new_gpa, new_semester_gpa,new_id ,
		   new_semester, new_grade, new_semester_hour, new_total_hour, new_earned_hour);
	if(target==0)
	{
		this->insertfirst(new_name, new_gpa, new_semester_gpa,new_id, 
		  new_semester, new_grade, new_semester_hour, new_total_hour, new_earned_hour);
		return;
	}
	else
	{
		for(int i=0;i<target-1;i++)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
	listsize++;
}
void linkedlist::search(int id){
	cout<<"\n";
    int c =0 ;
    student* temp = head ;
    if (head==NULL){
      cout <<"the linked list is empty \n" ;
    }
    else{
      
      while(temp!=NULL ){
        if (temp->id == id){
        	cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
        	cout<<temp->id<<"\t"<<temp->name<<"\t"<<temp->gpa<<"\t"<<temp->semester_gpa<<"\t        "<<temp->grade<<"\t   "<<
		temp->total_hour<<"\t            "<<temp->semester_hour<<"\t            "<<temp->earned_hour<<"\t"<<"\n";
          c = 1;
          break ;
        }
        else{
          temp=temp->next ;
        }
        
      }
    
    }
    if(c==0){
      cout <<"not found \n" ;
    }
}
void linkedlist::sortlist()
{
  student*previous;
  student*q;
  previous=head;
  q=NULL;
  int temp;
  if(head==NULL)
   {
     return ;
   }
  else
   {
    while(previous!=NULL)
     {
      q=previous->next;
      while(q!=NULL)
        {
         if(previous->id>q->id)
          {
           temp=previous->id;
           previous->id=q->id;
           q->id=temp;
          }
         q=q->next;
        }   
      previous=previous->next;
     }
   }
}
void linkedlist:: update_semester_gpa(int Id,float new_val)
{
   student*temp=head;
   if(head==NULL)
    {
     return;
    }
  while(temp!=NULL)
    {
      if(temp->id==Id)
	   {
         temp->semester_gpa=new_val;
       }
         temp=temp->next;
    }
}
 void linkedlist::update_gpa(int Id,float new_val){
 student*temp=head;
 if(head==NULL){
  return;
 }
 while(temp!=NULL){
  if(temp->id==Id){
   temp->gpa=new_val;
  }
   temp=temp->next;
 }
 }
void linkedlist::update_total_hours(int Id,int new_val)
 {
   student*temp=head;
   if(head==NULL)
    {
      return;
    }
   while(temp!=NULL)
    {
      if(temp->id==Id)
	   {
         temp->total_hour=new_val;
       }
      temp=temp->next;
    }
}
void linkedlist::update_earned_hours(int Id,int new_val)
{
     student*temp=head;
     if(head==NULL)
	 {
      return;
     }
     while(temp!=NULL)
     {
        if(temp->id==Id)
	    {
          temp->earned_hour=new_val;
        }
          temp=temp->next;
 }
}
void linkedlist::update_semester_hours(int Id,int new_val)
{
     student*temp=head;
     if(head==NULL)
	 {
       return;
     }
     while(temp!=NULL)
	 {
       if(temp->id==Id)
	   {
         temp->semester_hour=new_val;
       }
         temp=temp->next;
     }
}
void linkedlist::update_grade(int Id,string new_val)
{
   student*temp=head;
   if(head==NULL)
    {
      return;
    }
    while(temp!=NULL)
	{
      if(temp->id==Id)
	    {
           temp->grade=new_val;
        }
          temp=temp->next;
    }
}
void linkedlist::update_name(int Id,string new_val)
{
     student*temp=head;
     if(head==NULL)
	  {
        return;
      }
     while(temp!=NULL)
	 {
       if(temp->id==Id)
	    {
          temp->name=new_val;
        }
        temp=temp->next;
     }
}
void linkedlist::deletbegin()
    {
      student *previous;
      if(head==NULL)
       {
          cout<<"sorry,this list doesnot have any elements.."<<endl;
       }
          previous=head;
          head=previous->next;
          delete previous;
    }
void linkedlist::deletwhere(int item)
{
    student *previous;
    student *q;
    q=NULL;
    previous=head;
    while(previous!=NULL&&previous->id!=item)
     {
       q=previous;
       previous=previous->next;
     }
    if(previous==NULL)
      {
      	cout<<"SORRY,THIS OBJECT IS NOT FOUND..."<<endl;
	  }
    if(q==NULL)
      {
      	 head=previous->next;
	  }
    else
       {
       	q->next=previous->next;
	   }
  delete previous;
}
void linkedlist::deletatend()
{
       student*previous;
       previous=head;
       if(previous->next==NULL)
         {
            head=NULL;
            delete previous;
         }
       while(previous->next!=NULL)
        {
           previous=previous->next;
           delete previous->next;
           previous->next=NULL;
        }
}
void linkedlist::display_reverse()
	{
		if(head==NULL)
		{
			return;
		}
		 student*curr=head;
		 student*prev=NULL;
		 student*next=NULL;
		 while(curr!=NULL)
		 {
		 	next=curr->next;
		 	curr->next=prev;
		 	prev=curr;
		 	curr=next;
		 }
		 head=prev;
	}
class stack
{
  student* top;
  public:
    int listsize;
    stack()
    {
    top=NULL; 
    listsize=0;
    }
  bool IsEmpty()
  {
    if(top==NULL)
    return true;
    else
    return false;
  }
   void push(string name,float gpa,float semester_gpa,int id , string semester,string grade,int semester_hour,int total_hour,int earned_hour)
   {
     student* n=new student(name,gpa,semester_gpa,id,semester,grade,semester_hour, total_hour,earned_hour);
    n->name=name ;
    n->gpa=gpa ;
    n->semester_gpa=semester_gpa ;
    n-> id=id;
    n->semester=semester ;
    n->grade=grade; 
    n->semester_hour=semester_hour;
    n->total_hour=144;
    n->earned_hour=earned_hour;
    if(IsEmpty())
    {
    
    top=n;
    }
    else
    {
      n->next=top;
      top=n;
    }
  listsize++;
}
  void peak()
  {
    student* temp=top;
     cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
         "TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
    while(temp!=NULL)
    {
      cout<<temp->id<<"\t"<<temp->name<<"\t"<<temp->gpa<<"\t"<<temp->semester_gpa<<"\t        "<<temp->grade<<"\t   "<<
            temp->total_hour<<"\t            "<<temp->semester_hour<<"\t            "<<temp->earned_hour<<"\t"<<"\n";
            temp=temp->next;
    }
    cout<<endl;
  }
  void pop()
  {
    if (top==NULL)
    {
      cout<<"this stack is empty\n";
      exit(1);
    }
  else
  {
    cout<<top->id<<"\t"<<top->name<<"\t"<<top->gpa<<"\t"<<top->semester_gpa<<"\t        "<<top->grade<<"\t   "<<
            top->total_hour<<"\t            "<<top->semester_hour<<"\t            "<<top->earned_hour<<"\t"<<"\n";
    top=top->next;
    listsize--;
  }
  }
  
};
int main()
{
	system ("color 4");
		linkedlist *list=new linkedlist();
	int student_id;
	string n;
	 float g,x;
	 char h;
	cout<<"                                      Welcome to faculty of computer scince                                  \n\n\n "
	<<"                                  our project will show a student report card\n\n\n";
	
	
	
		
	int whatdo;
	cout<<"                           what function you want to apply\n";
	cout<<"      1-insert\n      2-sort\n      3-search\n      4-update\n      5-delete\n      6-display in reverse order\n      7-stack\n";
	cout<<"Enter no from 1 to 7\n";
	cin>>whatdo;
	 system("cls");
	if(whatdo==1)
	{
		cout<<"__________________ADD IN THE FIFST(BEGIN)\n";
	list->insertfirst("Ali", 3.0,3.1,42110246,"third", "B-", 18, 144,54);
	list->insertfirst("Ahmed", 3.1,3.2,42110242 ,"third", "B-", 18, 144, 54);
	cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
	list->traversal();
	cout<<"__________________append end\n";
	list->insertend("gh", 3.2,3.3,42110245,"third", "B", 18, 144, 54);
	cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
	list->traversal();
	cout<<"__________________addafter\n";
	list->insertafter("nada", 3.3,3.3,42110244 ,"third", "B+", 18, 144, 54,0);
	cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
	list->traversal();
	cout<<"___________________Insert at aspesific position\n";
	list->add_at("omar",3,3.6,42011034,"third","A",18,144,54,2);
	cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
	list->traversal();
	cout<<"_____________________taking input from user\n";
	do
	{
		cout<<"Do you want to add student \nclick y or n\n";
		char r;
		cin>>r;
		if(r=='y')
		{
		 	for(int i=0;i<1;i++)
			 {
			 	list->getline();
		     }
		    cout<<"_______________________after adding \n";
		    cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 	    	"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
	        list->traversal();
		 }
		else 
		{
			break;
		}
	}while(true);
	}
	else if(whatdo==2)
	{
		list->insertfirst("Ali", 3.0,3.1,42110243,"third", "B-", 18, 144,54);
	list->insertfirst("Ahmed", 3.1,3.2,42110242 ,"third", "B-", 18, 144, 54);
	list->insertend("gh", 3.2,3.3,42110245,"third", "B", 18, 144, 54);
	list->insertafter("nada", 3.3,3.3,42110244 ,"third", "B+", 18, 144, 54,0);
	cout<<"\n_________________________before sorting\n";
  	list->traversal();
  	cout<<"\n_________________________after sorting\n";
	list->sortlist();
	cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
	list->traversal();
	}
	else if(whatdo==3)
	{
		list->insertfirst("Ali", 3.0,3.1,42110243,"third", "B-", 18, 144,54);
	list->insertfirst("Ahmed", 3.1,3.2,42110242 ,"third", "B-", 18, 144, 54);
	list->insertend("gh", 3.2,3.3,42110245,"third", "B", 18, 144, 54);
	list->insertafter("nada", 3.3,3.3,42110244 ,"third", "B+", 18, 144, 54,0);
	cout<<" ___________________________The list of student\n";
	list->traversal();
	cout<<"\n\n\n\n\n__________________searching\n";
	cout<<"ENTER ID TO SEARCH\n";
	int id;
	cin>>id;
	list->search(id);
	do 
	{
		cout<<"YO WANT TO SEARCH AGAIN ?\n enter y or n\n";
		char r;
		cin>>r;
		if(r=='y')
		{
		cout<<"ENTER ID TO SEARCH\n";
     	cin>>id;
    	list->search(id);	
		}
		else 
		{
			break;
		}
	}while(true);
	}
	else if(whatdo==4)
	{
		list->insertfirst("Ali", 3.0,3.1,42110243,"third", "B-", 18, 144,54);
	list->insertfirst("Ahmed", 3.1,3.2,42110242 ,"third", "B-", 18, 144, 54);
	list->insertend("gh", 3.2,3.3,42110245,"third", "B", 18, 144, 54);
	list->insertafter("nada", 3.3,3.3,42110244 ,"third", "B+", 18, 144, 54,0);
		cout<<"\n_________________________before updating\n";
  	list->traversal();
    cout<<"do you want to change\npress y or n\n";
    char c;
    cin>>c;
    while(c=='y')
	{
    cout<<"what do you want to change\n \n1-gpa\n2-semester_gpa\n3-name\n4-grade"<<
    "\n5-semester_hours\n6-total_hours\n7-earned_hours\nclick no from 1 to 7\n";
    int answer;
    cin>>answer;
    if (answer==1)
	 {
       cout<<"enter student id and the new gpa\n";
       cin>>student_id>>g;
       list->update_gpa(student_id,g);
       cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 	 	"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
       list->traversal();
       break;
     }
    if (answer==2)
	 {
    	cout<<"enter student id and new semester_gpa\n";
        cin>>student_id>>g;
        list->update_semester_gpa(student_id,g);
        cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
        list->traversal();
        break;
     }
    if (answer==3)
	 {
        cout<<"enter student id and new name\n";
        cin>>student_id>>n;
        list->update_name(student_id,n);
        cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
        list->traversal();
        break;
     }
    if (answer==4)
	 {
       cout<<"enter student id and new grade\n";
       cin>>student_id>>n;
       list->update_grade(student_id,n);
       cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
        list->traversal();
        break;
    }
    if (answer==5)
	 {
       cout<<"enter student id and new semester_hours\n";
       cin>>student_id>>x;
       list->update_semester_hours(student_id,x);
       cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
        list->traversal();
        break;
     }
    if (answer==6)
	 {
     cout<<"enter student id and new total_hours\n";
     cin>>student_id>>x;
     list->update_total_hours(student_id,x);
     cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
     list->traversal();
     break;
     }
    if (answer==7)
	{
      cout<<"enter student id and new earned_hours\n";
      cin>>student_id>>x;
      list->update_earned_hours(student_id,x);
      cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
      list->traversal();
      break;
    }
}
}
  if(whatdo==5)
  {
  	list->insertfirst("Ali", 3.0,3.1,42110243,"third", "B-", 18, 144,54);
	list->insertfirst("Ahmed", 3.1,3.2,42110242 ,"third", "B-", 18, 144, 54);
	list->insertend("gh", 3.2,3.3,42110245,"third", "B", 18, 144, 54);
	list->insertafter("nada", 3.3,3.3,42110244 ,"third", "B+", 18, 144, 54,0);
  	cout<<"\n_________________________before deleting\n";
  	list->traversal();
  	cout<<"__________________delete begain\n";
  list->deletbegin();
  list->traversal();
  cout<<"__________________delete end\n";
  list->deletatend();
  list->traversal();
  int item;
  cout<<"please,enter the id to delete this student\n";
  cin>>item;
  cout<<"__________________delete certain\n";
  list->deletwhere(item);
  list->traversal();
  } 
  if(whatdo==6)
  {
  	list->insertfirst("Ali", 3.0,3.1,42110243,"third", "B-", 18, 144,54);
	list->insertfirst("Ahmed", 3.1,3.2,42110242 ,"third", "B-", 18, 144, 54);
	list->insertend("gh", 3.2,3.3,42110245,"third", "B", 18, 144, 54);
	list->insertafter("nada", 3.3,3.3,42110244 ,"third", "B+", 18, 144, 54,0);
	cout<<"                                                                              Before reverse\n\n\n\n\n";
	list->traversal();
	list->display_reverse();
	cout<<"                               \n\n\n\n\n                                               After reverse\n\n\n\n\n\n";
	list->traversal();
  }
  if(whatdo==7)
  {
  	  cout<<"\n___________________________stack\n";
     stack st;
  string n;
  float g,gp;
  int l,i,s_h,t_h,e_h;
  string s, gr;
    cout<<"Enter student data"<<endl;
    cout<<"Your Name: "<<endl;
    cin>>n;
    cout<<"Your semester gpa: "<<endl;
    cin>>g;
    cout<<"Your cgpa: "<<endl;
    cin>>gp;
    cout<<"Your ID:"<<endl;
    cin>>i;
    cout<<"Semester? "<<endl;
    cin>>s;
    cout<<"Grade:(A orA- and so on) "<<endl;
    cin>>gr;
    cout<<"semester hour?"<<endl;
    cin>>s_h;
    cout<<"earned hour?"<<endl;
    cin>>e_h;
    st.push(n,g,gp,i,s,gr,s_h,t_h,e_h);
    st.peak();
    cout<<endl;
    cout<<endl;
    do
  {
    cout<<"Do you want to add student(y or n)\n";
    char z;
    cin>>z;
    if(z=='y')
    {
    cout<<"Your Name: "<<endl;
    cin>>n;
    cout<<"Your semester gpa: "<<endl;
    cin>>g;
    cout<<"Your total gpa: "<<endl;
    cin>>gp;
    cout<<"Your ID:"<<endl;
    cin>>i;
    cout<<"Semester? "<<endl;
    cin>>s;
    cout<<"Grade:(A or A- and so on)"<<endl;
    cin>>gr;
    cout<<"semester hour?"<<endl;
    cin>>s_h;
    cout<<"earned hour?"<<endl;
    cin>>e_h;
    st.push(n,g,gp,i,s,gr,s_h,t_h,e_h);
     cout<<"\n_____________ display inforormation on the system by peek function\n";
    st.peak();
    cout<<endl;
    cout<<endl;
  }
  else
  {
    break;
    }  
  }while(true);
cout<<"student that was poped:"<<"\n\n";
 st.pop() ;
 cout<<"\n_____________ display inforormation on the system by peek function\n";
st.peak();
cout<<"                              End of project \n                           Thanks for your time\n";
  }
  do
  {
  	char qw;
  	cout<<"                                         \n\n\n         Do you want to use anthor function\npress y or n\n";
  	cin>>qw;
  	if (qw=='Y'||qw=='y')
  	{
  		 system("cls");
	cout<<"                           what function you want to apply\n";
	cout<<"      1-insert\n      2-sort\n      3-search\n      4-update\n      5-delete\n      6-display in reverse order\n      7-stack\n";
	cout<<"Enter no from 1 to 7\n";
	cin>>whatdo;
	 system("cls");
	if(whatdo==1)
	{
		cout<<"__________________ADD IN THE FIFST(BEGIN)\n";
	list->insertfirst("Ali", 3.0,3.1,42110246,"third", "B-", 18, 144,54);
	list->insertfirst("Ahmed", 3.1,3.2,42110242 ,"third", "B-", 18, 144, 54);
	cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
	list->traversal();
	cout<<"__________________append end\n";
	list->insertend("gh", 3.2,3.3,42110245,"third", "B", 18, 144, 54);
	cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
	list->traversal();
	cout<<"__________________addafter\n";
	list->insertafter("nada", 3.3,3.3,42110244 ,"third", "B+", 18, 144, 54,0);
	cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
	list->traversal();
	cout<<"___________________Insert at aspesific position\n";
	list->add_at("omar",3,3.6,42011034,"third","A",18,144,54,2);
	cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
	list->traversal();
	cout<<"_____________________taking input from user\n";
	do
	{
		cout<<"Do you want to add student \nclick y or n\n";
		char r;
		cin>>r;
		if(r=='y')
		{
		 	for(int i=0;i<1;i++)
			 {
			 	list->getline();
		     }
		    cout<<"_______________________after adding \n";
		    cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 	    	"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
	        list->traversal();
		 }
		else 
		{
			break;
		}
	}while(true);
	}
	else if(whatdo==2)
	{
		list->insertfirst("Ali", 3.0,3.1,42110243,"third", "B-", 18, 144,54);
	list->insertfirst("Ahmed", 3.1,3.2,42110242 ,"third", "B-", 18, 144, 54);
	list->insertend("gh", 3.2,3.3,42110245,"third", "B", 18, 144, 54);
	list->insertafter("nada", 3.3,3.3,42110244 ,"third", "B+", 18, 144, 54,0);
	cout<<"\n_________________________before sorting\n";
  	list->traversal();
  	cout<<"\n_________________________after sorting\n";
	list->sortlist();
	cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
	list->traversal();
	}
	else if(whatdo==3)
	{
		list->insertfirst("Ali", 3.0,3.1,42110243,"third", "B-", 18, 144,54);
	list->insertfirst("Ahmed", 3.1,3.2,42110242 ,"third", "B-", 18, 144, 54);
	list->insertend("gh", 3.2,3.3,42110245,"third", "B", 18, 144, 54);
	list->insertafter("nada", 3.3,3.3,42110244 ,"third", "B+", 18, 144, 54,0);
	cout<<" ___________________________The list of student\n";
	list->traversal();
	cout<<"\n\n\n\n\n__________________searching\n";
	cout<<"ENTER ID TO SEARCH\n";
	int id;
	cin>>id;
	list->search(id);
	do 
	{
		cout<<"YO WANT TO SEARCH AGAIN ?\n enter y or n\n";
		char r;
		cin>>r;
		if(r=='y')
		{
		cout<<"ENTER ID TO SEARCH\n";
     	cin>>id;
    	list->search(id);	
		}
		else 
		{
			break;
		}
	}while(true);
	}
	else if(whatdo==4)
	{
		list->insertfirst("Ali", 3.0,3.1,42110243,"third", "B-", 18, 144,54);
	list->insertfirst("Ahmed", 3.1,3.2,42110242 ,"third", "B-", 18, 144, 54);
	list->insertend("gh", 3.2,3.3,42110245,"third", "B", 18, 144, 54);
	list->insertafter("nada", 3.3,3.3,42110244 ,"third", "B+", 18, 144, 54,0);
		cout<<"\n_________________________before updating\n";
  	list->traversal();
    cout<<"do you want to change\npress y or n\n";
    char c;
    cin>>c;
    while(c=='y')
	{
    cout<<"what do you want to change\n \n1-gpa\n2-semester_gpa\n3-name\n4-grade"<<
    "\n5-semester_hours\n6-total_hours\n7-earned_hours\nclick no from 1 to 7\n";
    int answer;
    cin>>answer;
    if (answer==1)
	 {
       cout<<"enter student id and the new gpa\n";
       cin>>student_id>>g;
       list->update_gpa(student_id,g);
       cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 	 	"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
       list->traversal();
       break;
     }
    if (answer==2)
	 {
    	cout<<"enter student id and new semester_gpa\n";
        cin>>student_id>>g;
        list->update_semester_gpa(student_id,g);
        cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
        list->traversal();
        break;
     }
    if (answer==3)
	 {
        cout<<"enter student id and new name\n";
        cin>>student_id>>n;
        list->update_name(student_id,n);
        cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
        list->traversal();
        break;
     }
    if (answer==4)
	 {
       cout<<"enter student id and new grade\n";
       cin>>student_id>>n;
       list->update_grade(student_id,n);
       cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
        list->traversal();
        break;
     }
    if (answer==5)
	 {
       cout<<"enter student id and new semester_hours\n";
       cin>>student_id>>x;
       list->update_semester_hours(student_id,x);
       cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
        list->traversal();
        break;
     }
    if (answer==6)
	 {
     cout<<"enter student id and new total_hours\n";
     cin>>student_id>>x;
     list->update_total_hours(student_id,x);
     cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
     list->traversal();
     break;
     }
    if (answer==7)
	{
      cout<<"enter student id and new earned_hours\n";
      cin>>student_id>>x;
      list->update_earned_hours(student_id,x);
      cout<<"ID"<<"\t"<<"        NAME"<<"\t"<<"GPA"<<"\t"<< "SEMESTER GPA"<<"\t"<<"GRADE"<<"\t"<<
 		"TOTAL HOUR"<<"       SEMESTER HOUR"<<"\t"<<"EARNED HOUR"<<"\t"<<"\n";
      list->traversal();
      break;
    }
   }
	}
  if(whatdo==5)
  {
  	list->insertfirst("Ali", 3.0,3.1,42110243,"third", "B-", 18, 144,54);
	list->insertfirst("Ahmed", 3.1,3.2,42110242 ,"third", "B-", 18, 144, 54);
	list->insertend("gh", 3.2,3.3,42110245,"third", "B", 18, 144, 54);
	list->insertafter("nada", 3.3,3.3,42110244 ,"third", "B+", 18, 144, 54,0);
  	cout<<"\n_________________________before deleting\n";
  	list->traversal();
  	cout<<"__________________delete begain\n";
  list->deletbegin();
  list->traversal();
  cout<<"__________________delete end\n";
  list->deletatend();
  list->traversal();
  int item;
  cout<<"please,enter the id to delete this student\n";
  cin>>item;
  cout<<"__________________delete certain\n";
  list->deletwhere(item);
  list->traversal();
  } 
  if(whatdo==6)
  {
  	list->insertfirst("Ali", 3.0,3.1,42110243,"third", "B-", 18, 144,54);
	list->insertfirst("Ahmed", 3.1,3.2,42110242 ,"third", "B-", 18, 144, 54);
	list->insertend("gh", 3.2,3.3,42110245,"third", "B", 18, 144, 54);
	list->insertafter("nada", 3.3,3.3,42110244 ,"third", "B+", 18, 144, 54,0);
	cout<<"                                                                              Before reverse\n\n\n\n\n";
	list->traversal();
	list->display_reverse();
	cout<<"                               \n\n\n\n\n                                               After reverse\n\n\n\n\n\n";
	list->traversal();
  }
  if(whatdo==7)
  {
  	  cout<<"\n___________________________stack\n";
     stack st;
  string n;
  float g,gp;
  int l,i,s_h,t_h,e_h;
  string s, gr;
    cout<<"Enter student data"<<endl;
    cout<<"Your Name: "<<endl;
    cin>>n;
    cout<<"Your semester gpa: "<<endl;
    cin>>g;
    cout<<"Your cgpa: "<<endl;
    cin>>gp;
    cout<<"Your ID:"<<endl;
    cin>>i;
    cout<<"Semester? "<<endl;
    cin>>s;
    cout<<"Grade:(A orA- and so on) "<<endl;
    cin>>gr;
    cout<<"semester hour?"<<endl;
    cin>>s_h;
    cout<<"earned hour?"<<endl;
    cin>>e_h;
    st.push(n,g,gp,i,s,gr,s_h,t_h,e_h);
    st.peak();
    cout<<endl;
    cout<<endl;
    do
  {
    cout<<"Do you want to add student(y or n)\n";
    char z;
    cin>>z;
    if(z=='y')
    {
    cout<<"Your Name: "<<endl;
    cin>>n;
    cout<<"Your semester gpa: "<<endl;
    cin>>g;
    cout<<"Your total gpa: "<<endl;
    cin>>gp;
    cout<<"Your ID:"<<endl;
    cin>>i;
    cout<<"Semester? "<<endl;
    cin>>s;
    cout<<"Grade:(A or A- and so on)"<<endl;
    cin>>gr;
    cout<<"semester hour?"<<endl;
    cin>>s_h;
    cout<<"earned hour?"<<endl;
    cin>>e_h;
    st.push(n,g,gp,i,s,gr,s_h,t_h,e_h);
     cout<<"\n_____________ display inforormation on the system by peek function\n";
    st.peak();
    cout<<endl;
    cout<<endl;
  }
  else
  {
    break;
    }  
  }while(true);
cout<<"student that was poped:"<<"\n\n";
 st.pop() ;
 cout<<"\n_____________ display inforormation on the system by peek function\n";
st.peak();
cout<<"                              End of project \n                           Thanks for your time\n";
  }
	}
	else
	{
		break;
	}
  	
  }while(true);
}


