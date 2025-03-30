#include<iostream>
using namespace std;
class Librarian;
class Book{
	private:
		string title;
		int price;
		public:
			Book(string title,int price){
				this->title=title;
				this->price=price;
			}
			friend class Librarian;
};
class Librarian{
	public:
		void display(const Book& book){
			cout<<"Title: "<<book.title<<endl;
			cout<<"Price is : "<<book.price<<endl;
		}
		
		void discount(Book &book, int price){
			book.price-=price;
			cout<<"Discounted price is: "<<book.price<<endl;
		}
};
int main(){
	Book b("C++",300);
	Librarian l;
	l.display(b);
	l.discount(b,20);
	return 0;
}