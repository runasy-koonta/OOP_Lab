# include <iostream>
# include <vector>
using namespace std;

bool found_char(const char* s, char ch) {
	for (int i = 0; i < sizeof(s); i++) {
		if (s[i] == ch) {
			return true;
		}
	}
	return false;
}
int main() {
	const char* phrase = "phrase";

	for (char ch = 'a'; ch <= 'z'; ch++) { // 'a' == 65, 'z' == 97
		cout << ch << " is ";
		if (!found_char(phrase, ch))
			cout << "NOT";
		cout << " in (" << phrase <<")"  << endl;
	}

	return 0;
}
