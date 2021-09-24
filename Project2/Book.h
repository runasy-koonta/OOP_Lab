#ifndef BOOK_H
#define BOOK_H
#include <string>

class Book {
private:
	std::string title, author, genre;
	int year;
public:
	Book();
	void setTitle (std::string newTitle);
	void setAuthor (std::string newAuthor);
	void setYear (int newYear);
	void setGenre (std::string newGenre);
	std::string getTitle () const;
	std::string getAuthor () const;
	int getYear () const;
	std::string getGenre () const;
	void displayBook (std::ostream &out) const;
};
#endif