#include<iostream>
using namespace std;

class TourGuide{
	string name;
	int experience;
	string specialization;
	public:
	TourGuide(){}
	TourGuide(string name,int experience,string specialization){
		this->name=name;
		this->experience=experience;
		this->specialization=specialization;
	}
	void displaydetails(){
		cout<<"TourGuide Name: "<<name<<endl;
		cout<<"Tour Guide Experience: "<<experience<<endl;
		cout<<"TourGuide specialization: "<<specialization<<endl;
	}
	
};

class travelagency{
	TourGuide* guides[10];
	string agencyname;
	int guidecount=0;
	public:
		travelagency(string agencyname){
			this->agencyname=agencyname;
		}
	void addguide(TourGuide* guide){
		if(guidecount <10){
			guides[guidecount++]=guide;
		}else{
			cout<<"No more guide to add in "<<agencyname<<endl;
		}
	} 
	
	void display(){
		cout<<"Travel Agency Name: "<<agencyname<<endl;
		cout<<"Assigned Tour Guides: "<<endl;
		for(int i=0; i<guidecount; i++){
		guides[i]->displaydetails();
	}
}
};
int main(){
	travelagency agency("Travel and Tours");
	TourGuide* guide1=new TourGuide("Yash Raj",3,"Description");
	
	agency.addguide(guide1);
	agency.display();
	delete guide1;
	return 0;
}
