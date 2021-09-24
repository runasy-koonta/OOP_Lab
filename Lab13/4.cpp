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
	CStudent s[3];
	int inputNumber;
	string inputName, inputMajor;
	int length = 0;

	while (1) {
		cout << (length + 1) << " 번째 학생 입력" << endl;
		cout << "학번 : ";
		cin >> inputNumber;
		cout << "이름 : ";
		cin >> inputName;
		cout << "전공: ";
		cin >> inputMajor;
		
		bool flag = false;
		for (int i = 0; i < length; i++) {
			if (inputNumber == s[i].getNumber()) {
				cout << "- 중복된 학번이 존재합니다" << endl << endl;
				flag = true;
				continue;
			}
		}
		if (flag) continue;
		
		s[length++] = CStudent(inputNumber, inputName, inputMajor);
		cout << "- 입력 완료" << endl << endl;
		
		if (length > 2) {
			break;
		}
	}
	
	cout << "---- 모든 입력이 완료되었습니다 ----" << endl;
	for (int i = 0; i < 3; i++) {
		cout << (i + 1) << "학생정보" << endl;
		s[i].Display();
	}

	return 0;
}
