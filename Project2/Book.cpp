#ifndef BOOK_CPP
#define BOOK_CPP

#include "Book.h"
#include <iostream>
#include <string>
using namespace std;

Book::Book() {
	title = "";
	author = "";
	genre = "";
	year = 2016;
}
void Book::setTitle(string newTitle) {
	title = newTitle;
}
void Book::setAuthor(string newAuthor) {
	author = newAuthor;
}
void Book::setYear(int newYear) {
	year = newYear;
}
void Book::setGenre(string newGenre) {
	genre = newGenre;
}
string Book::getTitle() const {
	return title;
}
string Book::getAuthor() const {
	return author;
}
int Book::getYear() const {
	return year;
}
string Book::getGenre() const {
	return genre;
}
void Book::displayBook(ostream &out) const {
	out << "Title: " << title << endl;
	out << "Author: " << author << endl; 
	out << "Year: " << year << endl;
	out << "Genre: " << genre << endl;
}
#endif