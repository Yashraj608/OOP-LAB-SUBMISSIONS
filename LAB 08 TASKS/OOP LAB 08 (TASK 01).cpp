#include<iostream>
using namespace std;
class Humidity;

class Temperature{
	private:
		float temp;
		public:
			Temperature(float temp){
				this->temp=temp;
			}
			
			friend float calculateHeatIndex(Temperature t, Humidity h);
};
class Humidity{
	private:
		float humidity;
		public:
			Humidity(float humidity){
				this->humidity=humidity;
			}
				friend float calculateHeatIndex(Temperature t, Humidity h);
};

float calculateHeatIndex(Temperature t,Humidity h){
	float HeatIndex = t.temp + t.temp + h.humidity + t.temp*h.humidity + t.temp + h.humidity+ t.temp*h.humidity + t.temp*h.humidity + t.temp*h.humidity;
   // Formula may not be accurate//
	return HeatIndex;
}
int main(){
	Temperature temp(32.0);
	Humidity Hum(70.0);
	
	cout<<"Heat Index is : "<<calculateHeatIndex(temp,Hum)<<endl;
	return 0;
}