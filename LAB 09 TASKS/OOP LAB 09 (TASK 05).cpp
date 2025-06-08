#include<iostream>
using namespace std;
class Activity{
public:
virtual void CalculateCaloriesBurned()=0;
};

class Running : public Activity{
    protected:
    double time;
    double distance;
 public:
 Running(double time,double distance){
    this->distance=distance;
    this->time=time;
 }
 void CalculateCaloriesBurned() override{
    int caloriesBurned;
    caloriesBurned= 0.05 * distance*time;
    cout<<"Calories Burned through running is: "<<caloriesBurned<<endl;
 }
};

class Cycling : public Activity{
    protected:
    double speed;
    double time;
    public:
    Cycling(double speed,double time){
        this->speed=speed;
        this->time=time;
    }

    void CalculateCaloriesBurned() override{
     int caloriesBurned;
     caloriesBurned = speed*time*1.036;
     cout<<"Caloried Burned through Cycling is : "<<caloriesBurned<<endl;
    }
};
int main(){
    Activity*activities[2];
    activities[0] = new Running(22.0,100);
    activities[0]->CalculateCaloriesBurned();

    activities[1]= new Cycling(200,22.0);
    activities[1]->CalculateCaloriesBurned();
}
