#include<iostream>
using namespace std;

class Device{
	protected:
		int Deviceid;
		bool status;
	public:
		Device(int Deviceid,bool status){
			this->Deviceid=Deviceid;
			this->status=status;
		}
		
		virtual void display(){
			cout<<"Device id is: "<<Deviceid<<endl;
			cout<<"Status: "<<status<<endl;
		}
};

class Smartphone :virtual public Device{
	protected:
		float screensize;
		public:
			Smartphone(int Deviceid,float screensize,bool status):Device(Deviceid,status){
				this->screensize=screensize;
			}
			void display() override{
				Device::display();
				cout<<"Screen Size is :"<<screensize<<endl;
			}
};

class Smartwatch :virtual public Device{
	protected:
		bool heartratemonitor;
	public:
		Smartwatch(int Deviceid,bool status,bool heartratemonitor):Device(Deviceid,status){
			this->heartratemonitor=heartratemonitor;
		}
		
		void display() override{
			Device::display();
			cout<<"Heart Rate Monitor: "<<heartratemonitor<<endl;
		}
};

class SmartWearable : public Smartphone , public Smartwatch{
	protected:
		int stepcounter;
		public:
	SmartWearable(int stepcounter,int Deviceid,bool status,bool heartratemonitor,float screensize):Device(Deviceid,status),Smartphone(Deviceid,screensize,status),Smartwatch(Deviceid,status,heartratemonitor){
		this->stepcounter=stepcounter;
	}
	
	void display() override{
        cout<<"Screen Size: "<<screensize<<"inches"<< endl;
        cout<<"Heart Rate Monitor: "<<(heartratemonitor ? "Yes" : "No")<<endl;
        cout<<"Step Counter: " <<stepcounter<<"steps"<<endl;
    }
};
int main(){
	 int Deviceid, stepcounter;
    bool status, heartratemonitor;
    float screensize;

    cout<<"Enter Device ID: "<<endl;
    cin>>Deviceid;
    cout<<"Enter Device Status (1 for On, 0 for Off): "<<endl;
    cin>>status;
    cout<<"Enter Screen Size (in inches):"<<endl;
    cin>>screensize;
    cout<<"Does it have a Heart Rate Monitor? (1 for Yes, 0 for No): "<<endl;
    cin>>heartratemonitor;
    cout<<"Enter Step Counter value: "<<endl;
    cin>>stepcounter;
    
    SmartWearable S(stepcounter,Deviceid,status,heartratemonitor,screensize);
    S.display();
	return 0;
}
