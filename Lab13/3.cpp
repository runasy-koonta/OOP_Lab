#include <string>
#include <iostream>
using namespace std;

class CStudent {
	private:
		int number;
		string name;
		string major_subject;
	public:
		CStudent(): number(2018000000), name("홍길동"), major_subject("컴퓨터공학과") {
			
		}
		CStudent(int number, string name, string major_subject) {
			this->number = number;
			this->name = name;
			this->major_subject = major_subject;
		}
	
		void setNumber(int number) {
			this->number = number;
		}
		void setName(string name) {
			this->name = name;
		}
		void setMajor(string major_subject) {
			this->major_subject = major_subject;
		}
		
		int getNumber() {
			return this->number;
		}
		string getName() {
			return this->name;
		}
		string getMajor() {
			return this->major_subject;
		}
	
		void Display() {
			cout << "학번 : " << this->number << endl;
			cout << "이름 : " << this->name << endl;
			cout << "전공 : " << this->major_subject << endl << endl;
		}
};

int main() {
	CStudent s1;
	s1.Display();

	CStudent s2(1999000000, "공지철", "연극영화과"); 
	s2.Display();

	s1.setNumber(2006000000);
	s1.setName("민경훈");
	s1.setMajor("포스트모던");
	cout << "학번 :" << s1.getNumber() << endl;
	cout << "이름 :" << s1.getName() << endl;
	cout << "전공 :" << s1.getMajor() << endl;

	return 0;
}