#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
public:
	friend class KHUIS;
	
	Student() {
		this->numCourseTaken = 0;
	}
	Student(string name) {
		this->name = name;
		this->numCourseTaken = 0;
	}
	Student(string name, string id) {
		this->name = name;
		this->id = id;
		this->numCourseTaken = 0;
	}
	
	void setName(string name) {
		this->name = name;
	}
	void setId(string id) {
		this->id = id;
	}
	
	string getCode(int i) {
		return this->code[i];
	}
	string getName() {
		return this->name;
	}
	string getId() {
		return this->id;
	}
	
	friend ostream& operator<<(ostream& os, const Student& stu);
	
	void addCourse(string code) {
		this->code[(this->numCourseTaken)++] = code;
	}
private: //맴버 변수
	string name; //학생 이름
	string id;   //학생 아이디
	string code[100]; //들은 수업(course)의 code (최대 100개)
	int numCourseTaken; //들은 수업의 총 개수
};

ostream& operator<<(ostream& os, const Student& stu) {
	os << "ID: " << stu.id << "\tName: " << stu.name << "\tCourses(taking): ";
	for (int i = 0; i < stu.numCourseTaken; i++) {
		os << stu.code[i] << " ";
	}
	return os;
}

class Course {
public:
	friend class KHUIS;
	void setName(string name) {
		this->name = name;
	}
	void setCode(string code) {
		this->code = code;
	}
	
	friend ostream& operator<<(ostream& os, const Course& stu);
	
	string getName() {
		return this->name;
	}
	string getCode() {
		return this->code;
	}
private: //맴버 변수
	string name; //수업의 이름
	string code; //수업의 코드
};
ostream& operator<<(ostream& os, const Course& c) {
	os << "Code :" << c.code << "\tName :" << c.name;
	return os;
}

class KHUIS {
//종정시 클래스: 학생정보와 학생이 듣고있는 수업 정보를 출력, Student class와 Course class에서 friend class로 정의됨
public:
	//학생의 정보를 입력으로 받아 학생정보 출력
	// 학생의 들은 수업(code)에 대한 수업 이름을 Course class에서 찾아서 출력
	//numCourse(int)는 _course 배열의 길이를 의미
	void printInfo(Student& _stu, Course* _course, int numCourse) {
		cout << "[Student and Course Information]" << endl;
		cout << _stu << endl;
		for (int i = 0; i < _stu.numCourseTaken; i++) {
			for (int j = 0; j < numCourse; j++) {
				if (_course[j].code == _stu.code[i]) {
					cout << _course[j] << endl;
					break;
				}
			}
		}
		cout << endl;
	}
};

int main() {
	int numTotalCourse = 3; //총 과목의 개수
	Course *pCourse = new Course[numTotalCourse];
	pCourse[0].setName("객체지향프로그래밍");
	pCourse[0].setCode("CSE100");
	pCourse[1].setName("영상처리");
	pCourse[1].setCode("CSE200");
	pCourse[2].setName("머신러닝");
	pCourse[2].setCode("CSE300");

	cout << pCourse[0].getCode() << '\t' << pCourse->getName() << endl; // 그림1. (1)
	cout << setw(50) << setfill('-') << "" << endl;

	cout << pCourse[0] << endl; // 그림1. (2)
	cout << pCourse[1] << endl;
	cout << pCourse[2] << endl;
	cout << setw(50) << setfill('-') << "" << endl;

	Student stu1("홍길동", "20181004"), stu2;
	stu1.addCourse("CSE100");
	stu1.addCourse("CSE200");

	stu2.setName("김영희");
	stu2.setId("20182000");
	stu2.addCourse("CSE100");
	stu2.addCourse("CSE300");

	cout << stu1.getId() << '\t' << stu1.getName() << '\t' << stu1.getCode(0) << endl; // 그림1. (3)
	cout << setw(50) << setfill('-') << "" << endl;

	cout << stu1 << endl; // 그림1. (4)
	cout << stu2 << endl;
	cout << setw(50) << setfill('-') << "" << endl;

	KHUIS khuis;
	khuis.printInfo(stu1, pCourse, numTotalCourse); // 그림1. (5)
	khuis.printInfo(stu2, pCourse, numTotalCourse);

	delete[] pCourse;
	return 0;
}