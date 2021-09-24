#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(void) {
	ifstream input_handle_1("3_input1"), input_handle_2("3_input2");
	ofstream output_handle("output.txt");
	
	string str;
    while (getline(input_handle_1, str)) {
		output_handle << str << endl;
	}
    while (getline(input_handle_2, str)) {
		output_handle << str << endl;
	}
	
	return 0;
}