#include"iostream"
using namespace std;
class professor{
	string name;
	string department;
	public:
		professor(){
		}
		professor(string name,string department){
			this->name=name;
			this->department=department;
		}
		void showdetails(){
			cout<<"Professor Name: "<<name<<endl;
			cout<<"Professor department: "<<department<<endl;
		}
	
};

class university{
	string name;
	professor* teachers[5];
	int count=0;
	public:
		university(){
			//constructor
		}
		university(string name){
			this->name=name;
		}
		void addteacher(professor* teacher){
			if(count<5){
				teachers[count++]=teacher;
			}else{
				cout<<"No more professor to add in "<<name<< " university"<<endl;
			}
		}
		
		void display(){
			cout<<"University name: "<<name<<endl;
			cout<<"Professors in university:"<<endl;
			for(int i=0;i<count;i++){
				teachers[i]->showdetails();
			}
		}
		
};

int main(){
	university u1("Fast");
	professor* teacher1=new professor("yash raj","Data science");
	
	u1.addteacher(teacher1);
	u1.display();
	return 0;
}
