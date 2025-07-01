#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;
class FileException: public exception{
public:
const char* what() const noexcept{
    return "File Exception Occurred..";
} 
};

class FileNotFoundException : public FileException{
    public:
    const char* what() const noexcept override{
        return "FileNotFoundException - File Not Found";
    }
};

class PermissionDeniedException : public FileException{
    public:
    const char* what() const noexcept override{
        return "PermissionDeniedException - Access Denied";
    }
};

void readFile(const string& filename){
    if(filename=="missing.txt"){
        throw FileNotFoundException();
    }
    else if(filename=="secret.txt"){
        throw PermissionDeniedException();
    }else{
        cout<<"Reading "<<filename<<" success"<<endl;
    }
}
int main(){
string filename;
cout<<"Enter filename to read.. "<<endl;
cin>>filename;
try {
    readFile(filename);
}
catch (FileNotFoundException& e) {
    cout << "Reading '" << filename << "': " << e.what() << endl;
}
catch (PermissionDeniedException& e) {
    cout << "Reading '" << filename << "': " << e.what() << endl;
}
catch (FileException& e) {
    cout << "Reading '" << filename << "': " << e.what() << endl;
}
    return 0;
}