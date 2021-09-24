#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//예외처리: try/catch구문, throw문
//1. 예외가 발생하는 부분을 try에 넣는다
//2. 예외가 발생하면 catch 구문이 실행된다
class FileNotFoundException : public exception {
	string message;
public:
	FileNotFoundException(string _m) :
		message("File not found: " + _m) {}
	virtual const char* what() const throw() {
		return message.c_str();
	}

};
vector<int> load_vector(string filename) {
	ifstream fin(filename);

	if (!fin) {
		throw FileNotFoundException(filename);
		
	}

	vector<int> result;
	int num, value;
	// 파일로부터 값을 result에 저장
	// 파일의 form: size, elements (5 1 2 3 4 4)
	fin >> num;
	for (int i = 0; i < num; i++) { int t; fin >> t; result.push_back(t); }
	return result;
}
int main() {
	try {
		vector<int> v = load_vector("values.dat");
		/* 구현 */ // values.dat 파일에서 vector 로드
		for (int elem : v)
			cout << elem << ' ';
		cout << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}
