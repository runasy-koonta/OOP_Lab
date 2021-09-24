#ifndef BOOKLIST_CPP
#define BOOKLIST_CPP

#include "BookList.h"
#include "Book.cpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

BookList::BookList() {
	count = 0;
	size = 10;
}

void BookList::addBook(Book b) {
	if (count < size) {
		books[count++] = b;
	}
}
void BookList::addBookAt(Book b, int location) {
	if (location < 0) location = 0;
	else if (location > count) location = count;
	
	Book books_new[10];
	
	int looking = 0;
	for (int i = 0; i < count + 1; i++) {
		if (location == i) {
			books_new[i] = b;
		} else {
			books_new[i] = books[looking++];
		}
	}
	count++;
	copy(begin(books_new), end(books_new), begin(books));
}
void BookList::displayBooks(ostream &out) const {
    out << "Books in my list:" << endl;
    for ( int i=0;i<count; i++ )
        books[i].displayBook(out);
}
Book BookList::findBook(int location) const {
	Book def;
	if (location < 0 || location > count) return def;
	else return books[location];
}
Book BookList::removeBook(int location) {
	Book ret;
	if (location < 0 || location > count) return ret;
	else {
		Book books_new[10];
		ret = books[location];
		int looking = 0;
		for (int i = 0; i < count; i++) {
			if (location == i) {
				continue;
			}
			books_new[i] = books[looking++];
		}
		count--;
		return ret;
	}
}

#endif