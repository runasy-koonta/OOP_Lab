#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string data = "사랑,프로그래밍,의자,사랑의바보,영통역,천년의사랑,냉장고,객체지향", delimiter = ",", word;
	int pos, startPos = 0;
	while ((pos = data.find(delimiter, startPos)) != string::npos) {
		word = data.substr(startPos, pos - startPos);
		if (word.find("사랑") != string::npos) {
			cout << word << " ";
		}
		startPos = pos + delimiter.length();
	}
	return 0;
}