#include<iostream>
using namespace std;
class Print;
class Get{
	friend class Print;		//friend class
private:
	static string Class;     //static varible
	int roll_no, telefone_no;
	string first_name,middle_name,last_name,date_of_birth,blood_grp,address;
	char division;
	
public:
		Get()     // default constructor
		{
			first_name=" ";
			middle_name=" ";
			last_name=" ";
			roll_no=0;
			division=' ';
			date_of_birth=" ";
			blood_grp=" ";
			address=" ";
			telefone_no=0;
		}
		
		Get(Get &obj)		// copy constructor
		{
			first_name=obj.first_name;
			middle_name=obj.middle_name;
			last_name=obj.last_name;
			roll_no=obj.roll_no;
			division=obj.division;
			date_of_birth=obj.date_of_birth;
			blood_grp=obj.blood_grp;
			address=obj.address;
			telefone_no=obj.telefone_no;
		}
		
		static void Class_name()		//static member function
		{
			cout<<"Class of student : "<<Class<<endl;
		}
		
		void insert()
		{
			cout<<"Enter First Name of student : "; 
			cin>>first_name;
			cout<<"Enter Middle Name of student : "; 
			cin>>middle_name;
			cout<<"Enter last Name of student : "; 
			cin>>last_name;
			cout<<"Enter Roll no of student : "; 
			cin>>roll_no;			
			cout<<"Enter division of student : "; 
			cin>>division;
			cout<<"Enter Date of birth of student : "; 
			cin>>date_of_birth;
			cout<<"Enter Blood Group of student : "; 
			cin>>blood_grp;
			cout<<"Enter Address(without space) of student : "; 
			cin>>address;
			cout<<"Enter Telefone no of student : "; 
			cin>>telefone_no;
			
				
			try{					//exception handling
				if (roll_no <= 0)
					throw 0;
			}
			catch(int a){
				cout<<"\nExeption occured: Roll no not less or equal to 0"<<endl;
				roll_no=0;
			}
			
		}
		
		inline void student()	// inline function
		{
			cout<<"=== information of Roll No. "<<this->roll_no<<" ===\n"<<endl;	//this pointer
		}
		
		~Get()		//destructor
		{
		}
};

string Get::Class="SE";

class Print{
	
public:
		Print()		// default constructor
		{
			
		}
	
		void display(Get &obj)
		{
			obj.student();
			cout<<"Name of student : "<<obj.first_name<<" "<<obj.middle_name<<" "<<obj.last_name<<endl; 
			cout<<"Roll no of student : "<<obj.roll_no<<endl;
			Get::Class_name();
			cout<<"division of student : "<<obj.division<<endl;
			cout<<"Date of birth of student : "<<obj.date_of_birth<<endl;
			cout<<"Blood Group of student : "<<obj.blood_grp<<endl;
			cout<<"Address of student : "<<obj.address<<endl;
			cout<<"Telefone no of student : "<<obj.telefone_no<<endl;
		
		}
		~Print()	//destructor
		{
			
		}
	
};

int main(){
	int students;
	cout<<"Enter no of students : ";
	cin>>students;
	
	Get* obj1 = new Get[students];		//dynamic memory allocation - new operator
	Print* obj2 = new Print[students];
	
	for(int i=0;i<students;i++){
		cout<<endl;
		cout<<"=== Enter information of student "<<i+1<<" ===\n"<<endl;
		obj1[i].insert();
		cout<<endl;
	}
	for(int i=0;i<students;i++){
		obj2[i].display(obj1[i]);
		cout<<endl;
	}
	
	delete [] obj1;			//dynamic memory allocation - delete operator
	delete [] obj2;
	return 0;
}
