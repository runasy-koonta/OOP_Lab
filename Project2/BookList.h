#ifndef BOOKLIST_H
#define BOOKLIST_H
#include "Book.cpp"

class BookList {
private:
	Book books[10];
	int count, size;
	
	void slideUp(int location);
	void slideDown(int location);
public:
	BookList ();
	void addBookAt (Book b, int location);
	void addBook (Book b);
	Book findBook (int location) const;
	Book removeBook (int location);
	void displayBooks (std::ostream &out) const;
};
#endif