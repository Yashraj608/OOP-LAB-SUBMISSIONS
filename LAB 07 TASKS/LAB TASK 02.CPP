#include<iostream>
using namespace std;
class Shape{
	protected:
	string color,position;
	float borderThickness;
	public:
		Shape(string color,string position,float borderThickness){
			this->color=color;
			this->position=position;
			this->borderThickness=borderThickness;
		}
	virtual	void draw() const =0;
	virtual	void calculateArea() const =0;
	virtual void calculatePerimeter()const =0;
	
};
class Rectangle : public Shape{
	protected:
		int height,width;
		public:
			Rectangle(string color,string position,int height,int width,float borderThickness=0.0):Shape(color,position,borderThickness){
				this->height=height;
				this->width=width;
			}
			void draw() const override{
				cout<<"Drawing Rectangle with "<<color<<" color having width "<<width<<" and height "<<height<<endl;
			}
			
			void calculateArea() const override{
				cout<<"Area of Rectangle is : "<<width*height<<endl;
			}
			
			void calculatePerimeter() const override{
				cout<<"Perimeter of Rectangle is : "<<((2*width) +(2*height))<<endl;
			}
};
class Triangle : public Shape{
	protected:
		int side1,side2,side3;
		public:
			Triangle(string color,string position,int side1,int side2,int side3,float borderThickness=0.0):Shape(color,position,borderThickness){
				this->side1=side1;
				this->side2=side2;
				this->side3=side3;
			}
			
			void draw() const override{
				cout<<"Drawing Triangle with sides: "<<side1<<" "<<side2<<" "<<side3<<" with "<<color<<" color"<<endl;
			}
			
			void calculateArea() const override{
				cout<<"Area of Triangle having sides: "<<side1<<" "<<side2<<" "<<side3<<" is: "<<0.5*side1*side2<<endl;
			}
			void calculatePerimeter() const override{
				cout<<"Perimeter of Triangle :"<<side1+side2+side3<<endl;
			}
};

class Circle : public Shape{
	protected:
		int radius;
		public:
			Circle(string color,string position,int radius,float borderThickness=0.0):Shape(color,position,borderThickness){
				this->radius=radius;
			}
			void draw() const override{
				cout<<"Drawing Circle at "<<position<<" position having radius: "<<radius<<" with color: "<<color<<endl;
			}
			
			void calculateArea() const override{
				cout<<"Area Of Circle having radius "<<radius<<" is"<<3.14*radius*radius<<endl;
			}
			
			void calculatePerimeter() const override{
				cout<<"Perimter of Circle having radius "<<radius<<" is: "<<2*3.14*radius<<endl;
			}
};
int main(){
	cout<<"------Circle Details------"<<endl;
	Circle C("Black","Center",3);
Shape*shape =&C;
shape->draw();
shape->calculateArea();
shape->calculatePerimeter();

	cout<<"------Triangle Details------"<<endl;
	Triangle T("pink","left",22.0,3,2,1);
	shape =&T;
	shape->draw();
	shape->calculateArea();
	shape->calculatePerimeter();
	
	cout<<"------Rectangle Details------"<<endl;
	Rectangle R("red","Top Left Corner",2,3,2.0);
	shape =&R;
	shape->draw();
	shape->calculateArea();
	shape->calculatePerimeter();
	return 0;
}
