#include<iostream>
using namespace std;
class movie{
	string title;
	string director;
	int duration;
	public:
		movie(){
		}
		movie(string title,string director,int duration){
			this->title=title;
			this->director=director;
			this->duration=duration;
		}
		void displaydetails(){
			cout<<"Movie Name: "<<title<<endl;
			cout<<"Director: "<<director<<endl;
			cout<<"Movie Duration: "<<duration<<endl;
		}
		void updatemovie(string title,string director,int duration){
			this->title=title;
			this->director=director;
			this->duration=duration;
		}
	    
	    ~movie(){
		}
};

class cinemahall{
		movie m[5]; //composition//
		string cinemaname;
		int count=0;
	public:
		cinemahall(string cinemaname){
		this->cinemaname=cinemaname;
		}
		
		void addmovie(string title,string director,int duration){
			if(count<5){
				m[count].updatemovie(title,director,duration);
				count++;
			}
			else{
				cout<<"No Other Movies To show"<<endl;
			}
		}
		
		void displayhalldetails(){
			cout<<"Cinema Hall Name: "<<cinemaname<<endl;
			cout<<"Available Movies:"<<endl;
			for(int i=0;i<count;i++){
				m[i].displaydetails();
			}
		}
};

int main(){
	cinemahall karachi("Nuplex");
	karachi.addmovie("Titanic","unknown",123);
	karachi.addmovie("Mrs","unknown",321);
	karachi.addmovie("Where the crawdads sing","unknown",345);
	karachi.addmovie("paatallok","unknown",654);
	karachi.addmovie("Unknown","Yash",79);
	karachi.displayhalldetails();
	
}
