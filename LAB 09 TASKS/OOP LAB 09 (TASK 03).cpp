//book.h//
#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<string>
using namespace std;

class Book{
	private:
	string title,author,ISBN;
	public:
		Book(string t,string a, string i);
		string gettitle()const;
		string getAuthor()const;
		string getISBN()const;
};
#endif


//book.cpp//
#include"Book.h"
#include<iostream>
using namespace std;

Book::Book(string t , string a, string i){
	this->title=t;
	this->author=a;
	this->ISBN=i;
}

string Book::gettitle() const{
	return title;
}

string Book::getAuthor()const{
	return author;
}

string Book::getISBN()const{
	return ISBN;
}


//main.cpp//
#include<iostream>
#include"Book.cpp"

using namespace std;
int main(){
	Book my("crawdads","yash raj","110983-9");
	cout<<"Title : "<<my.gettitle()<<endl;
	cout<<"Author : "<<my.getAuthor()<<endl;
	cout<<"ISBN : "<<my.getISBN()<<endl;
}
