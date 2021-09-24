#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Student {
	private:
	string name;
	int number;
	string studentMajor;
	vector<string> subjects;
	vector<char> grades;
	
	public:
	Student(): name("default"), number(0), studentMajor("depart") {}
	Student(string name, int number, string studentMajor) {
		this->name = name;
		this->number = number;
		this->studentMajor = studentMajor;
	}
	
	void setName(string name) {
		this->name = name;
	}
	void setID(int ID) {
		this->number = ID;
	}
	void setDpt(string dpt) {
		this->studentMajor = dpt;
	}
	
	void print() {
		cout << this->name << " " << this->number << " " << this->studentMajor << endl;
	}
	
	void addGrade(string subject, char grade) {
		subjects.push_back(subject);
		grades.push_back(grade);
	}
	
	float getGPA() {
		int sum = 0;
		for (int i = 0; i < grades.size(); i++) {
			switch (grades.at(i)) {
				case 'A': sum += 4; break;
				case 'B': sum += 3; break;
				case 'C': sum += 2; break;
				case 'D': sum += 1; break;
				case 'F': sum += 0; break;
			}
		}
		return (float) sum / grades.size();
	}
	
	void printGrades() {
		for (int i = 0; i < subjects.size(); i++) {
			cout << subjects.at(i) << " " << grades.at(i) << endl;
		}
		cout << "GPA : " << this->getGPA() << endl;
	}
	
	void getYear(int year) {
		int adm_year = this->number / 1000000, g = year - adm_year;
		switch (g) {
			case 0:
				cout << "Freshmen(1학년)";
				break;
			case 1:
				cout << "Sophomore(2학년)";
				break;
			case 2:
				cout << "Junior(3학년)";
				break;
			case 3:
				cout << "Senior(4학년)";
				break;
			default:
				cout << "About to graduate(5학년)";
				break;
		}
		cout << endl;
	}
};

int main() {
	Student Harry("Harry", 2017310973, "CS");
	Harry.print();
	Harry.getYear(2019);
	Harry.addGrade("programming", 'A');
	Harry.addGrade("Basic Circuit", 'B');
	Harry.printGrades();
	cout << "\n\n";

	Student Ron;
	Ron.print();
	cout << "\n";
	Ron.setName("Ron");
	Ron.setID(2014103959);
	Ron.setDpt("EE");
	Ron.print();
	Ron.getYear(2019);
	Ron.addGrade("Computer Architecture", 'B');
	Ron.addGrade("Maching Learning", 'B');
	Ron.addGrade("Computer Vision", 'C');
	Ron.printGrades();
	cout << "\n\n";

	return 0;
}
