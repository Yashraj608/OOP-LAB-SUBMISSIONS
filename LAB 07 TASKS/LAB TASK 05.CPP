#include<iostream>
using namespace std;
class Media{
protected:
string title,publisher,publicationDate;
int uniqueId;
public:
Media(string title,string publisher,int uniqueId,string publicationDate){
	this->title=title;
	this->publisher=publisher;
	this->uniqueId=uniqueId;
	this->publicationDate=publicationDate;
}	

virtual void displayInfo(){
	cout<<"Title: "<<title<<endl;
	cout<<"Publisher: "<<publisher<<endl;
	cout<<"Id: "<<uniqueId<<endl;
	cout<<"Publication Date: "<<publicationDate<<endl;
}

    string getTitle() {
	 return title;
	  }
    string getPublisher() { 
	return publisher; 
	}
    int getUniqueId() {
	 return uniqueId; 
	 }

};

class Book : public Media{
protected:
string author;
	int ISBN,pagenum;
	public:
		Book(string title,string publisher,int uniqueId,string publicationDate,string author,int ISBN,int pagenum):Media(title,publisher,uniqueId,publicationDate){
			this->author=author;
			this->ISBN=ISBN;
			this->pagenum=pagenum;
		}
		
		void displayInfo() override{
			Media::displayInfo();
			cout<<"Author: "<<author<<endl;
			cout<<"ISBN : "<<ISBN<<endl;
			cout<<"Number of pages: "<<pagenum<<endl;
		}
	
};

class DVD : public Media{
protected:
string director;
int rating ,duration;
public:
DVD(string title,string publisher,int uniqueId,string publicationDate,string director,int rating,int duration):Media(title,publisher,uniqueId,publicationDate){
this->director=director;
this->rating=rating;
this->duration=duration;
}

void displayInfo() override{
	Media::displayInfo();
	cout<<"Director: "<<director<<endl;
	cout<<"Duration: "<<duration<<" minutes"<<endl;
	cout<<"Rating: "<<rating<<endl;
}
};

class CD: public Media{
protected:
string artist,genre;
int numberofTracks;
public:
CD(string title,string publisher,int uniqueId,string publicationDate,string artist,string genre,int numberofTracks):Media(title,publisher,uniqueId,publicationDate){
	this->genre=genre;
	this->artist=artist;
	this->numberofTracks=numberofTracks;
}	

void displayInfo() override{
	Media::displayInfo();
	cout<<"Artist :"<<artist<<endl;
	cout<<"Genre: "<<genre<<endl;
	cout<<"Number Of Tracks: "<<numberofTracks<<endl;
}
};

void search(Media* items[], int itemCount, string title) {
    cout << "Searching by title: " << title << "\n";
    bool found = false;
    for (int i = 0; i < itemCount; i++) {
        if (items[i]->getTitle() == title) {
            items[i]->displayInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No media found with title: " << title << "\n";
    }
}

void search(Media* items[], int itemCount, int uniqueId) {
    cout<<"Searching by unique ID: "<<uniqueId<<endl;
    bool found = false;
    for (int i = 0;i<itemCount;i++) {
        if (items[i]->getUniqueId() == uniqueId) {
            items[i]->displayInfo();
            found = true;
        }
    }
    if (!found) {
        cout<<"No media found with unique ID: "<<uniqueId<<endl;
    }
}
int main(){
	
    Media* items[20];
    int itemCount = 0;

    items[itemCount++] = new Book("crawdads","Dawn",222,"12-09-2023","Yash Raj",200, 350);
    items[itemCount++] = new DVD("Squid Game","Japan",299,"00-00-2023","Japani",7, 120);
    items[itemCount++] = new CD("Money Heist","Italy",223,"00-00-0000","professor","Action/Mystery",3);

    for (int i = 0; i < itemCount; i++) {
        items[i]->displayInfo();
        cout << "================\n";
    }

    string choice;
    cout<<"Do you want to search?: "<<endl;
    cin >> choice;

    if (choice == "yes" || choice == "YES") {
        int searchType;
        cout << "Search by: 1. Title"<<endl;
		cout<<" 2. Unique ID: "<<endl;
        cin >> searchType;

        if (searchType == 1) {
            string title;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            search(items, itemCount,title);
        } else if (searchType == 2) {
            int uniqueId;
            cout << "Enter unique ID: ";
            cin >> uniqueId;
            search(items, itemCount, uniqueId);
        } else {
            cout << "Invalid choice." << endl;
        }
    }
	return 0;
}
