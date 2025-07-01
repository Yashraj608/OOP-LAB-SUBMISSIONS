#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;
class InvalidValueException : public exception{
    public:
    const char* what() const noexcept override{
        return "Invalid value..";
    }
};

void validateAge(int age){
    if(age < 0 || age > 120){
        throw InvalidValueException();
    }
}
int main(){
try{
     validateAge(-3);
}
catch(InvalidValueException& e){
    cout<<"Caught exception is : "<<e.what()<<endl;
}
    return 0;
}