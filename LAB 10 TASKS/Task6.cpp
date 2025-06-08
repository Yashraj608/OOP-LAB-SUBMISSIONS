#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;
class InventoryItem{
    public:
    int itemid;
    char ItemName[20];
    
};
int main(){
    InventoryItem item;
    item.itemid = 222;
    strcpy(item.ItemName,"mobile");

    ofstream myfile("Inventory.dat",ios::binary);
    if(myfile.is_open()){
        cout<<"File opened successfully"<<endl;
    
    myfile.write(reinterpret_cast<char*>(&item),sizeof(item));
    myfile.close();
    }
    else{
        cerr<<"File failed to open"<<endl;
    }

    InventoryItem item1;
    ifstream yourfile("Inventory.dat", ios::binary);
    if(!yourfile){
        cerr<<"Failed to open file"<<endl;
    }else{
        yourfile.read(reinterpret_cast<char*>(&item1),sizeof(item1));
        yourfile.close();

        cout<<"Item name: "<<item.ItemName<<endl;
        cout<<"Item id: "<<item.itemid<<endl; 
    }
}