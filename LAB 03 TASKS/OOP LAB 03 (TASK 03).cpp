//EVENT MANAGEMET SYSTEM//
//Yash Raj//
//24k-0737//
#include<iostream>
using namespace std;

class planner{
	private:
	string task[31];
	
	public:
		planner(){
			for(int i=0;i<31;i++){
				task[i]="No task";
			}
		}
	void addtask(int day,string newtask){
    if(day>=1&&day<=31){
    	task[day-1]= newtask;
    	cout<<"Task Added for "<<day<<"day"<<endl;
	}
	else{
		cout<<"Invalid Day"<<endl;
	}
		
	}
	
	void remove(int day){
		if(day>=1&&day<=31){
			task[day-1]="No task";
			cout<<"Task Removed"<<endl;
		}
	}
	
	void display(){
		cout<<"Schedule For the month is:"<<endl;
		for(int i=0;i<31;i++){
			cout<<"Day"<<i+1<<":"<<task[i]<<endl;
		}
	}
};

int main(){
	planner hassanplan;
	
	hassanplan.addtask(2,"Birthday party");
	hassanplan.display();
	hassanplan.remove(2);
}